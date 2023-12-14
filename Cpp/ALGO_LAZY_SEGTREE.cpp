struct segtree_lazy
{
    long long size;
    long long NO_OPEERATION = 0;
    long long NEUTRAL_ELEMENT = 0;

    vector<long long> opr, values;

    long long modify_op(ll a, ll b, ll len) // add to segment
    {
        if (b == NO_OPEERATION)
            return a;
        return a + b * len; // how will the values and opr change if you add b to the segment?
        // notice that modify_op is being used correctly on values and opr
    }
    long long calc_op(ll a, ll b) // sum of segment
    {
        return a + b;
    }
    void apply_mod_op(ll &a, ll b, ll len)
    {
        a = modify_op(a, b, len);
    }

    void init(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        values.assign(2 * size, 0); //**
        opr.assign(2 * size, NO_OPEERATION);
    }

    void propogate(ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
            return;
        ll mid = (lx + rx) / 2;
        apply_mod_op(opr[2 * x + 1], opr[x], 1);
        apply_mod_op(opr[2 * x + 2], opr[x], 1);
        apply_mod_op(values[2 * x + 1], opr[x], mid - lx);
        apply_mod_op(values[2 * x + 2], opr[x], rx - mid);
        opr[x] = NO_OPEERATION;
    }

    // we are going from lx included to rx excluded
    void range_update(ll l, ll r, ll val, ll x, ll lx, ll rx)
    {
        propogate(x, lx, rx);
        if (lx >= r || l >= rx)
            return;
        if (lx >= l && rx <= r)
        {
            apply_mod_op(opr[x], val, 1);
            apply_mod_op(values[x], val, rx - lx);
            return;
        }
        ll mid = (lx + rx) / 2;
        range_update(l, r, val, 2 * x + 1, lx, mid);
        range_update(l, r, val, 2 * x + 2, mid, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }
    void range_update(ll l, ll r, ll val)
    {
        range_update(l, r, val, 0, 0, size);
    }

    long long query(ll l, ll r, ll x, ll lx, ll rx)
    {
        propogate(x, lx, rx);
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return values[x];
        ll mid = (lx + rx) / 2;
        auto left = query(l, r, 2 * x + 1, lx, mid);
        auto right = query(l, r, 2 * x + 2, mid, rx);
        return calc_op(left, right);
    }
    long long query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }

    // void print_segtree()
    // {
    //     cout << "segtree values: \n";
    //     ll cnt = 1, cur = 0;
    //     for (int i = 0; i < 2 * size; i++)
    //     {
    //         cur++;
    //         cout << values[i] << " ";
    //         if (cur == cnt)
    //         {
    //             cout << "\n";
    //             cur = 0;
    //             cnt *= 2;
    //         }
    //     }
    //     cout << "\n";
    // }
};
//https://cses.fi/problemset/task/2166/
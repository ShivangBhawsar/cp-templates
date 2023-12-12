struct segtree
{
    ll size;
    vector<ll> tree;
    ll neutral_element = 0;

    ll combine(ll a, ll b)
    {
        return a + b;
    }

    void init(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0); //**
    }

    // we are going from lx included to rx not included
    void point_update(ll i, ll val, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = val; //**
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid)
            point_update(i, val, 2 * x + 1, lx, mid);
        else
            point_update(i, val, 2 * x + 2, mid, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void point_update(ll i, ll val)
    {
        point_update(i, val, 0, 0, size);
    }

    ll query(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return neutral_element;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        ll mid = (lx + rx) / 2;
        ll left = query(l, r, 2 * x + 1, lx, mid);
        ll right = query(l, r, 2 * x + 2, mid, rx);
        return combine(left, right);
    }
    ll query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }

    // void print_segtree()
    // {
    //     cout << "segtree: \n";
    //     ll cnt = 1, cur = 0;
    //     for (int i = 0; i < 2 * size; i++)
    //     {
    //         cur++;
    //         cout << tree[i] << " ";
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
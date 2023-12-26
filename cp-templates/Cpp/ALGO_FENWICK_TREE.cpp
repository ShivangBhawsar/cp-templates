// 0 based indexing
// To declare write FenwickTree f(arr) or FenwickTree f(size)
struct FenwickTree
{
    vector<ll> bit; // binary indexed tree
    ll n;

    FenwickTree(ll n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(ll r)
    {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
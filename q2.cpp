#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
// g++ "-Wl,--stack,1078749825" q1.cpp -o ab
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree <ll,null_type,less <ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define tup(i, x) get<i>(x)
#define rem 1000000007
#define PI 3.141592653589793238462643383279502
struct mergesorttree
{
    ll size;
    vector<vector<ll>> tree;
    vector<vector<ll>> presum;

    vector<ll> merge(vector<ll> &a, vector<ll> &b)
    {
        vector<ll> result;
        ll x = 0, y = 0;
        ll n = a.size(), m = b.size();
        while (x < n && y < m)
        {
            if (a[x] < b[y])
            {
                result.push_back(a[x]);
                x++;
            }
            else
            {
                result.push_back(b[y]);
                y++;
            }
        }
        while (x < n)
        {
            result.push_back(a[x]);
            x++;
        }
        while (y < m)
        {
            result.push_back(b[y]);
            y++;
        }
        return result;
    }

    void init(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, {});
        presum.assign(2 * size, {});
    }

    // we are going from lx included to rx not included
    void point_update(ll i, ll val, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = {(int)val};
            presum[x] = {val};
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid)
            point_update(i, val, 2 * x + 1, lx, mid);
        else
            point_update(i, val, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        presum[x] = tree[x];
        for (int i = 1; i < presum[x].size(); i++)
        {
            presum[x][i] += presum[x][i - 1];
        }
    }

    void point_update(ll i, ll val)
    {
        point_update(i, val, 0, 0, size);
    }

    void get_ranges(ll l, ll r, ll x, ll lx, ll rx, vector<ll> &nodes)
    {
        if (lx >= r || l >= rx)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            nodes.push_back(x);
            return;
        }
        ll mid = (lx + rx) / 2;
        get_ranges(l, r, 2 * x + 1, lx, mid, nodes);
        get_ranges(l, r, 2 * x + 2, mid, rx, nodes);
    }

    pair<ll, ll> sumandcountless(ll l, ll r, ll x) // sum and count of elements lesser than or equal to x
    {
        vector<ll> nodes;
        get_ranges(l, r, 0, 0, size, nodes);

        pair<ll, ll> ans = {0, 0};
        for (auto y : nodes)
        {
            ll idx = upper_bound(all(tree[y]), x) - tree[y].begin();
            idx--;
            if (idx >= 0)
            {
                ans.first += presum[y][idx];
                ans.second += idx + 1;
            }
        }

        return ans;
    }

    pair<ll, ll> sumandcountmore(ll l, ll r, ll x) // sum and count of elements more than or equal to x
    {
        vector<ll> nodes;
        get_ranges(l, r, 0, 0, size, nodes);

        pair<ll, ll> ans = {0, 0};
        for (auto y : nodes)
        {
            ll idx = lower_bound(all(tree[y]), x) - tree[y].begin();
            idx--;
            ans.first += presum[y].back();
            ans.second += tree[y].size();
            if (idx >= 0)
            {
                ans.first -= presum[y][idx];
                ans.second -= (idx + 1);
            }
        }
        return ans;
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

int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    /*ll tests;
    cin>>tests;
    for (int gg=0;gg<tests;gg++)
    {}*/
    ll n;
    cin >> n;
    mergesorttree mst;
    mst.init(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mst.point_update(i, x);

        pair<ll, ll> small = mst.sumandcountless(0, i + 1, x - 2);
        pair<ll, ll> large = mst.sumandcountmore(0, i + 1, x + 2);

        ans += small.second * x - small.first;
        ans += large.second * x - large.first;
    }
    cout << ans << "\n";
}
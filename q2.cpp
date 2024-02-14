// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")
// g++ "-Wl,--stack,1078749825" q1.cpp -o ab
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define tup(i, x) get<i>(x)
#define rem 1000000007
#define PI 3.141592653589793238462643383279502
map<pair<ll, ll>, ll> idx;
vector<pair<ll, ll>> arr;
struct DSU
{
    vector<ll> parent, rank, minx, miny, maxx, maxy;
    // we can maintain commutative and associative operations as well like sum of elements in a set or minimum etc.
    void init(ll n)
    {
        parent.assign(n, 0);
        rank.assign(n, 0);
        minx.assign(n, 1e9);
        miny.assign(n, 1e9);
        maxx.assign(n, -1);
        maxy.assign(n, -1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            minx[i] = min(minx[i], arr[i].first);
            maxx[i] = max(maxx[i], arr[i].first);
            miny[i] = min(miny[i], arr[i].second);
            maxy[i] = max(maxy[i], arr[i].second);
        }
    }
    ll find_set(ll v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;
            minx[a] = min(minx[a], minx[b]);
            miny[a] = min(miny[a], miny[b]);
            maxx[a] = max(maxx[a], maxx[b]);
            maxy[a] = max(maxy[a], maxy[b]);
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests;
    cin >> tests;
    for (int gg = 0; gg < tests; gg++)
    {
        idx.clear();
        arr.clear();
        ll n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            arr.push_back({x, y});
        }
        for (int i = 0; i < m; i++)
        {
            idx[arr[i]] = i;
        }
        DSU dsu;
        dsu.init(m);
        for (int i = 0; i < m; i++)
        {
            {
                pair<ll, ll> p = arr[i];
                p.first++;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }
            {
                pair<ll, ll> p = arr[i];
                p.second++;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }
            {
                pair<ll, ll> p = arr[i];
                p.first--;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }
            {
                pair<ll, ll> p = arr[i];
                p.second--;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }

            {
                pair<ll, ll> p = arr[i];
                p.second--;
                p.first--;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }

            {
                pair<ll, ll> p = arr[i];
                p.second++;
                p.first++;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }

            {
                pair<ll, ll> p = arr[i];
                p.second--;
                p.first++;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }

            {
                pair<ll, ll> p = arr[i];
                p.second++;
                p.first--;
                if (idx.find(p) != idx.end())
                {
                    dsu.union_sets(idx[p], i);
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            ll minx = dsu.minx[i];
            ll miny = dsu.miny[i];
            ll maxx = dsu.maxx[i];
            ll maxy = dsu.maxy[i];
            if (maxx == n && minx == 1)
            {
                flag = false;
                break;
            }
            if (maxy == n && miny == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")
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
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
struct RollingHashDouble
{
    ll p1 = 998244353, p2 = 1000000009, rem1 = 1000000007;
    vector<pair<ll, ll>> prehash, powerval;
    ll n;

    void init(string &s)
    {
        this->n = s.length();
        prehash.assign(n, {0, 0});
        powerval.assign(n, {1, 1});

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                powerval[i] = {(powerval[i - 1].first * p1) % rem1, (powerval[i - 1].second * p2) % rem1};

            prehash[i].first = ((s[i] - 'a' + 1) * powerval[i].first) % rem1;
            prehash[i].second = ((s[i] - 'a' + 1) * powerval[i].second) % rem1;
            if (i > 0)
            {
                prehash[i].first = (prehash[i].first + prehash[i - 1].first) % rem1;
                prehash[i].second = (prehash[i].second + prehash[i - 1].second) % rem1;
            }
        }
    }

    pair<ll, ll> computeHash(ll l, ll r) // compute hash of substring from L to R both included, 0 based
    {
        pair<ll, ll> res = prehash[r];
        if (l - 1 >= 0)
        {
            res.first = (rem1 + res.first - prehash[l - 1].first) % rem1;
            res.second = (rem1 + res.second - prehash[l - 1].second) % rem1;
        }
        if (l != 0)
        {
            res.first *= modInverse(powerval[l].first, rem1);
            res.first %= rem1;
            res.second *= modInverse(powerval[l].second, rem1);
            res.second %= rem1;
        }
        return res;
    }
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
}
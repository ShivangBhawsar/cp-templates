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
int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests;
    cin >> tests;
    for (int gg = 0; gg < tests; gg++)
    {
        ll n, q;
        cin >> n >> q;
        vector<vector<ll>> arropr;
        vector<pair<ll, ll>> range;
        vector<ll> curopr;
        ll right = -1, infi = 1e18;
        ld rightd = -1;
        infi++;
        for (int i = 0; i < n; i++)
        {
            ll b, x;
            cin >> b >> x;
            // cout << "RIGHT: " << right << "\n";
            if (rightd > 1e18)
            {
                // arropr.pop_back();
                // range.pop_back();
                continue;
            }
            if (b == 1)
            {
                curopr.push_back(x);
                right++;
                rightd += 1;
            }
            else
            {
                arropr.push_back(curopr);
                range.push_back({right - (ll)curopr.size() + 1, right});
                curopr.clear();
                arropr.push_back({-1, x});

                rightd = (rightd + 1) * ((ld)x + 1) - 1;
                if (rightd <= 2e18)
                {
                    range.push_back({right + 1, (right + 1) * (x + 1) - 1});
                    right = (right + 1) * (x + 1) - 1;
                }
                else
                {
                    range.push_back({right + 1, 1e18});
                    right = 1e18;
                }
            }
        }
        if (!curopr.empty())
        {
            arropr.push_back(curopr);
            range.push_back({right - (ll)curopr.size() + 1, right});
        }

        while (arropr.size() > 130)
        {
            arropr.pop_back();
            range.pop_back();
        }

        ll sz = range.size();
        // for (int i = 0; i < sz; i++)
        // {
        //     cout << "arropr: ";
        //     for (auto x : arropr[i])
        //     {
        //         cout << x << " ";
        //     }
        //     cout << "\n";
        //     cout << "range: " << range[i].first << " " << range[i].second << "\n";
        // }
        while (q--)
        {
            ll k;
            cin >> k;
            k--;
            ll ans = 0;
            for (int i = sz - 1; i >= 0; i--)
            {
                if (k >= range[i].first && k <= range[i].second)
                {
                    if (arropr[i][0] == -1)
                    {
                        k %= range[i].first;
                    }
                    else
                    {
                        ans = arropr[i][k - range[i].first];
                    }
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
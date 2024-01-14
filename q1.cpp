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
void getDivisors(ll n, vector<ll> &fac)
{
    for (int i = 2; i <= sqrtl(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                fac.push_back(i);
            }
            else
            {
                fac.push_back(i);
                fac.push_back(n / i);
            }
        }
    }
    fac.push_back(1);
}
int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests;
    cin >> tests;
    for (int gg = 0; gg < tests; gg++)
    {
        // ll n;
        // cin >> n;
        ll mxval = 0;
        for (int n = 1; n <= 1e6; n++)
        {
            // vector<ll> arr(n);
            // for (int i = 0; i < n; i++)
            // {
            //     cin >> arr[i];
            // }
            // if (n == 1)
            // {
            //     cout << "1\n";
            //     continue;
            // }
            vector<ll> fac;
            getDivisors(n, fac);
            sort(all(fac));
            ll sz = fac.size();
            vector<deque<ll>> facs;
            // cout << facs.size() << "\n";
            vector<bool> used(n + 1, false);
            while (true)
            {
                ll cur = 0;
                deque<ll> curfac;
                for (int i = sz - 1; i >= 0; i--)
                {
                    if (used[i])
                    {
                        continue;
                    }
                    if (cur == 0 || cur % fac[i] == 0)
                    {
                        curfac.push_front(fac[i]);
                        cur = fac[i];
                        used[i] = true;
                    }
                }
                if (curfac.empty())
                {
                    break;
                }
                facs.push_back(curfac);
            }
            mxval = max(mxval, (ll)facs.size());
        }
        cout << "mxval: " << mxval << "\n";
        ll ans = 1;
        // cout << "facs:\n";
        // for (auto &f : facs)
        // {
        //     for (auto x : f)
        //     {
        //         cout << x << " ";
        //     }
        //     cout << "\n";
        // }
        // for (auto &f : facs)
        // {
        //     ll low = 0, high = f.size();
        //     while (low < high)
        //     {
        //         ll mid = (low + high) / 2;
        //         ll k = f[mid];
        //         vector<ll> gcd(k);
        //         for (int i = 0; i < k; i++)
        //         {
        //             gcd[i] = abs(arr[i + k] - arr[i]);
        //             ll p = i + k;
        //             while (p + k < n)
        //             {
        //                 gcd[i] = __gcd(gcd[i], abs(arr[p + k] - arr[p]));
        //                 p += k;
        //             }
        //         }
        //         ll fgcd = gcd[0];
        //         for (auto &x : gcd)
        //         {
        //             fgcd = __gcd(fgcd, x);
        //         }
        //         if (fgcd == 1)
        //         {
        //             low = mid + 1;
        //         }
        //         else
        //         {
        //             high = mid;
        //         }
        //     }
        //     ans += ((ll)f.size() - low);
        // }
        // cout << ans << "\n";
    }
}
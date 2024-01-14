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
        vector<pair<ll, ll>> arropr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arropr[i].first >> arropr[i].second;
        }
        vector<pair<ll, ll>> query(q);
        for (int i = 0; i < q; i++)
        {
            cin >> query[i].first;
            query[i].first--;
            query[i].second = i;
        }
        sort(all(query));
        ll pos = 0;
        vector<ll> ans(q, 0);
        vector<ll> arr;
        ll left = 0, right = -1;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            if (arropr[i].first == 1)
            {
                arr.push_back(arropr[i].second);
                right++;
            }
            else
            {
                right = (right + 1) * (arropr[i].second + 1) - 1;
                left = right - arr.size() + 1;
                // after the query set left=right-arr.size();
            }
            while (pos < q && query[pos].first <= right)
            {
                ans[query[pos].second] = arr[(query[pos].first - left) % arr.size()];
                
                pos++;
            }
            cout << "arr: ";
            for (auto x : arr)
            {
                cout << x << " ";
            }
            cout << "\n";
            cout << "left: " << left << " right: " << right << "\n\n";
        }
        for (int i = 0; i < q; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
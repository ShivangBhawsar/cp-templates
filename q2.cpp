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
int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests;
    cin >> tests;
    for (int gg = 0; gg < tests; gg++)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                arr[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] % arr[i] == 0)
            {
                arr[i + 1]++;
            }
        }
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
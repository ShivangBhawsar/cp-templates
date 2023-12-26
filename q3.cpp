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
bool isvalid(const string &s, const vector<string> &arr, ll n)
{
    vector<ll> fre(26);
    bool flag = false;
    for (auto x : s)
    {
        fre[x - 'a']++;
        if (fre[x - 'a'] >= 2)
        {
            flag = true;
        }
    }
    for (auto &x : arr)
    {
        vector<ll> idx;
        for (int i = 0; i < n; i++)
        {
            if (x[i] != s[i])
            {
                idx.push_back(i);
            }
        }
        if (idx.size() != 0 && idx.size() != 2)
        {
            return false;
        }
        if (idx.size() == 2)
        {
            if (s[idx[0]] != x[idx[1]] || s[idx[1]] != x[idx[0]])
            {
                return false;
            }
        }
        if (idx.size() == 0 && !flag)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    /*ll tests;
    cin>>tests;
    for (int gg=0;gg<tests;gg++)
    {}*/
    ll k, n;
    cin >> k >> n;
    vector<string> arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    arr.resize(distance(arr.begin(), unique(all(arr))));
    if (arr.size() == 1)
    {
        swap(arr[0][0], arr[0][1]);
        cout << arr[0] << "\n";
        return 0;
    }
    string s1 = arr[0], s2 = arr[1];
    vector<ll> idx;
    for (int z = 0; z < n; z++)
    {
        if (s1[z] != s2[z])
        {
            idx.push_back(z);
        }
    }

    if (idx.size() > 4)
    {
        cout << "-1\n";
        return 0;
    }
    if (isvalid(s1, arr, n)) // O(n*k)
    {
        cout << s1 << "\n";
        return 0;
    }
    if (isvalid(s2, arr, n))
    {
        cout << s2 << "\n";
        return 0;
    }
    for (int x = 0; x < n; x++)
    {
        for (auto y : idx)
        {
            if (x == y)
            {
                continue;
            }
            swap(s1[x], s1[y]);
            if (isvalid(s1, arr, n)) // O(n*k)
            {
                cout << s1 << "\n";
                return 0;
            }
            swap(s1[x], s1[y]);
            swap(s2[x], s2[y]);
            if (isvalid(s2, arr, n))
            {
                cout << s2 << "\n";
                return 0;
            }
            swap(s2[x], s2[y]);
        }
    }
    cout << "-1\n";
}
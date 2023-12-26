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

typedef __int128 ll128;
__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { return x > y; }

// ll128 n = read();
// print(n)
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
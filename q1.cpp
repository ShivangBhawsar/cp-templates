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
#define rem 998244353
#define PI 3.141592653589793238462643383279502

const int mod = 1000000007;
const int mod2 = 998244353;

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

template <const int mod>
class Mint
{
    long long val;

public:
    Mint(long long _val)
    {
        val = (_val % mod + mod) % mod;
    }
    Mint()
    {
        val = 0;
    }
    Mint operator+(Mint b)
    {
        return Mint((this->val + b.val) % mod);
    }
    Mint operator-(Mint b)
    {
        return Mint(this->val - b.val + mod) % mod;
    }
    Mint operator*(Mint b)
    {
        return Mint((this->val * b.val) % mod);
    }
    Mint operator/(Mint b)
    {
        return (Mint(power(b(), mod - 2, mod)) * (*this));
    }
    long long &operator()()
    {
        return val;
    }
    Mint operator+=(Mint b)
    {
        return *this = *this + b;
    }
    Mint operator-=(Mint b)
    {
        return *this = *this - b;
    }
    Mint operator*=(Mint b)
    {
        return *this = *this * b;
    }
    Mint operator/=(Mint b)
    {
        return *this = *this / b;
    }
    int operator%(int modulo)
    {
        return val % modulo;
    }
    int operator%(Mint modulo)
    {
        return val % (modulo());
    }
    Mint operator++()
    {
        return *this = *this + Mint(1);
    }
    Mint operator=(int x)
    {
        return (*this).val = (x % mod + mod) % mod;
    }
    Mint operator^(Mint pow)
    {
        return Mint(power((*this)(), pow(), mod));
    }
};
template <const int mod>
istream &operator>>(istream &in, Mint<mod> &a)
{
    return in >> a();
}
template <const int mod>
ostream &operator<<(ostream &outt, Mint<mod> a)
{
    return outt << a();
}
template <const int mod>
Mint<mod> operator+(int mul, Mint<mod> m)
{
    return m + mul;
}
template <const int mod>
Mint<mod> operator*(int mul, Mint<mod> m)
{
    return m * Mint<mod>(mul);
}
template <const int mod>
Mint<mod> operator-(int sub, Mint<mod> m)
{
    return Mint<mod>(sub) - m;
}
template <const int mod>
Mint<mod> operator/(int div, Mint<mod> m)
{
    return Mint<mod>(div) / m;
}
template <const int mod>
Mint<mod> operator^(int base, Mint<mod> m)
{
    return Mint<mod>(base) ^ m;
}

using mint = Mint<1000000007>;
using mint2 = Mint<998244353>;
mint operator"" _m(unsigned long long x)
{
    return mint(x);
}
mint2 operator"" _m2(unsigned long long x)
{
    return mint2(x);
}

mint2 proot = 3, iproot = mint2(1) / 3;

struct Polynomial
{
    vector<mint2> a;
    Polynomial(int n)
    {
        if ((n & (n - 1)))
        {
            while ((n & (n - 1)))
            {
                n = (n & (n - 1));
            }
            n *= 2;
        }
        a.resize(n);
    }
    Polynomial(vector<int> v, int n)
    {
        if ((n & (n - 1)))
        {
            while ((n & (n - 1)))
            {
                n = (n & (n - 1));
            }
            n *= 2;
        }
        a.resize(n);
        for (int i = 0; i < v.size(); i++)
            a[i] = v[i];
    }
    Polynomial(vector<int> v)
    {
        *this = Polynomial(v, v.size());
    }
    int size()
    {
        return a.size();
    }
    mint2 &operator[](int x)
    {
        return a[x];
    }
    void resize(int n)
    {
        if ((n & (n - 1)))
        {
            while ((n & (n - 1)))
            {
                n = (n & (n - 1));
            }
            n *= 2;
        }
        a.resize(n, 0);
    }
};

void fft(Polynomial &p, bool invert = false)
{
    int n = p.size();
    mint2 root = ((invert ? iproot : proot) ^ ((mod2 - 1) / n));
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = (n >> 1);
        while ((j & bit))
        {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j)
        {
            swap(p[i], p[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        mint2 eff_root = root;
        for (int i = len; i < n; i <<= 1)
        {
            eff_root *= eff_root;
        }
        for (int i = 0; i < n; i += len)
        {
            mint2 w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                auto u = p[i + j], v = w * p[i + j + len / 2];
                p[i + j] = u + v, p[i + j + len / 2] = u - v;
                w *= eff_root;
            }
        }
    }
    if (invert)
    {
        mint2 NInverse = mint2(1) / n;
        for (int i = 0; i < n; i++)
            p[i] *= NInverse;
    }
}

Polynomial operator*(Polynomial p1, Polynomial p2)
{
    int n = p1.size() + p2.size();
    p1.resize(n);
    p2.resize(n);
    fft(p1);
    fft(p2);
    for (int i = 0; i < p1.size(); i++)
        p1[i] *= p2[i];
    fft(p1, true);
    return p1;
}

Polynomial go(vector<int> &v, int l, int r)
{
    if (l == r)
    {
        return Polynomial(vector<int>{1, v[l]});
    }
    int mid = (l + r) / 2;
    return go(v, l, (l + r) / 2) * go(v, (l + r) / 2 + 1, r);
}

// reference: https://www.codechef.com/viewsolution/1045245053

signed main()
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
    map<ll, ll> fre;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        fre[x]++;
    }
    vector<int> arr;
    ll maxdistinct = 0;
    maxdistinct = max(maxdistinct, (ll)fre.size());
    for (auto x : fre)
    {
        arr.push_back((power(2, x.second, rem) + rem - 1) % rem);
    }
    Polynomial result = go(arr, 0, arr.size() - 1);
    ll N = result.size();
    // cout << "result: ";
    // for (int i = 0; i < N; i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << "\n";
    // cout << "N: " << N << "\n";
    vector<mint2> pre(N);
    pre[0] = result[0];
    for (int i = 1; i < N; i++)
    {
        pre[i] = pre[i - 1] + result[i];
    }
    // cout << "pre: ";
    // for (int i = 0; i < N; i++)
    // {
    //     cout << pre[i] << " ";
    // }
    // cout << "\n";
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l > maxdistinct)
        {
            cout << "0\n";
            continue;
        }
        r = min(r, maxdistinct);
        mint2 ans = pre[r] - pre[l - 1];
        cout << ans << "\n";
    }
}
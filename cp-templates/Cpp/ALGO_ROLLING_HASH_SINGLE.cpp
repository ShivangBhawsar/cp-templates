struct RollingHashSingle
{
    ll p1 = 1000000009, rem1 = 1000000007;
    vector<ll> prehash, powerval;
    ll n;

    void init(string &s)
    {
        this->n = s.length();
        prehash.assign(n, 0);
        powerval.assign(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                powerval[i] = (p1 * powerval[i - 1]) % rem1;

            prehash[i] = ((s[i] - 'a' + 1) * powerval[i]) % rem1;
            if (i > 0)
            {
                prehash[i] = (prehash[i] + prehash[i - 1]) % rem1;
            }
        }
    }

    ll computeHash(ll l, ll r) // compute hash of substring from L to R both included, 0 based
    {
        ll res = prehash[r];
        if (l - 1 >= 0)
        {
            res = (rem1 + res - prehash[l - 1]) % rem1;
        }
        if (l != 0)
        {
            res *= modInverse(powerval[l], rem1);
            res %= rem1;
        }
        return res;
    }
};
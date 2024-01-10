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
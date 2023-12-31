const ll MAXN = 1000000;
vector<ll> seive(MAXN + 1);

void sievefun()
{
    seive[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (seive[i] == 0)
        {
            seive[i] = i;
            for (ll j = i; j < MAXN; j += i)
                if (seive[j] == 0)
                    seive[j] = i;
        }
    }
}
set<ll> getFactorization(ll x)
{
    set<ll> ret;
    while (x != 1)
    {
        ret.insert(seive[x]);
        x = x / seive[x];
    }
    return ret;
}
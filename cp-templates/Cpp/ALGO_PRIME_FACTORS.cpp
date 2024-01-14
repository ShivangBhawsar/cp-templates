void primeFactors(ll n, vector<ll> &fac)
{
    while (n % 2 == 0)
    {
        fac.push_back(2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrtl(n); i = i + 2)
    {
        while (n % i == 0)
        {
            fac.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        fac.push_back(n);
}
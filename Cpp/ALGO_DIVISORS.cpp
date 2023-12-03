void getDivisors(ll n, vector<ll> &fac)
{
    for (int i = 1; i <= sqrtl(n); i++)
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
}
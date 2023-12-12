void printDivisors(ll n, vector<ll> &v1)
{
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
            {
                v1.push_back(i);
            }

            else // Otherwise print both
            {
                v1.push_back(i);
                v1.push_back(n / i);
            }
        }
    }
}
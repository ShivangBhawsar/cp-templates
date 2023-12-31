const ll mod = 1000000007; // CHANGE THE MODULO VALUE AS PER YOUR CONVINIENCE OK AND DON'T PASS IT IN THE METHOD

vector<vector<ll>> Miden(ll n)
{
    vector<vector<ll>> mat(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 1;
    }
    return mat;
}

vector<vector<ll>> Mmult(vector<vector<ll>> &matA, vector<vector<ll>> &matB)
{
    vector<vector<ll>> ans(matA.size(), vector<ll>(matB[0].size()));
    for (int i = 0; i < matA.size(); i++)
    {
        for (int j = 0; j < matB[0].size(); j++)
        {
            for (int k = 0; k < matA[0].size(); k++)
            {
                (ans[i][j] += (matA[i][k] * matB[k][j]) % mod);
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

vector<vector<ll>> Mpow(vector<vector<ll>> mat, ll n, ll y)
{
    vector<vector<ll>> ans = Miden(n);
    while (y > 0)
    {
        if (y & 1)
        {
            ans = Mmult(ans, mat);
        }
        y = y >> 1;
        mat = Mmult(mat, mat);
    }
    return ans;
}
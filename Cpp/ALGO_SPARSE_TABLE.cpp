struct sparseTable
{
    ll MAXN, K;
    vector<ll> log;
    vector<vector<ll>> st;

    void init(ll n, ll k)
    {
        MAXN = n;
        K = k;
        st.assign(MAXN, vector<ll>(K + 1, 0));
        log.assign(MAXN + 1, 0);
        log[1] = 0;
        for (int i = 2; i <= MAXN; i++)
        {
            log[i] = log[i / 2] + 1;
        }
    }

    // F(a,b) = a+b or F(a,b) = max(a,b)
    void computeST(vector<ll> &arr)
    {
        for (ll i = 0; i < MAXN; i++)
            st[i][0] = F(arr[i]);

        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= MAXN; i++)
                st[i][j] = F(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    // O(log(N))
    void getSum(ll L, ll R)
    {
        ll sum = 0;
        for (int j = K; j >= 0; j--)
        {
            if ((1 << j) <= R - L + 1)
            {
                sum += st[L][j];
                L += 1 << j;
            }
        }
    }

    // O(1) for getting Max or Min
    ll getMax(ll L, ll R)
    {
        int j = log[R - L + 1];
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }
};
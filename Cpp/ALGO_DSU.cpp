struct DSU
{
    vector<ll> parent, rank, cnt;
    // we can maintain commutative and associative operations as well like sum of elements in a set or minimum etc.
    void init(ll n)
    {
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        cnt.assign(n + 1, 1); // assign values as per requirement
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    ll find_set(ll v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;
            cnt[a] += cnt[b]; // or whatever operation it is

            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
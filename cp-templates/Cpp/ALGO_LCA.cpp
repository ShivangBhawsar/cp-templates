struct LCA
{
    // Assuming number of nodes < (1<<19) ~ <=5e5
    vector<ll> tin, tout;
    vector<vector<ll>> parent;

    void init(ll root, vector<vector<ll>> &adj, ll n)
    {
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        parent.assign(n + 1, vector<ll>(20, 0));
        vector<bool> visit(n + 1, false);
        ll timer = 0;
        dfs(root, adj, visit, timer);
        for (ll j = 1; j < 20; j++)
        {
            for (ll i = 1; i <= n; i++)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    void dfs(ll node, vector<vector<ll>> &adj, vector<bool> &visit, ll &timer)
    {
        tin[node] = timer++;
        visit[node] = true;
        for (auto &x : adj[node])
        {
            if (!visit[x])
            {
                parent[x][0] = node;
                dfs(x, adj, visit, timer);
            }
        }
        tout[node] = timer++;
    }
    bool is_ancestor(ll u, ll v) // is u an ancestor of v
    {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    ll lca(ll u, ll v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        // Upar jao, jabtak ancestor just milne na pae
        for (ll i = 19; i >= 0; --i)
        {
            if (parent[u][i] != 0 && is_ancestor(parent[u][i], v) == false)
                u = parent[u][i];
        }
        return parent[u][0];
    }
};
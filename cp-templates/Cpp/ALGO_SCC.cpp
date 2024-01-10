struct SCC
{
    ll n;
    vector<vector<ll>> adj, adj_rev;
    vector<bool> visit;
    vector<ll> topo, root;

    void init(ll n)
    {
        this->n = n;
        adj.assign(n + 1, {});
        adj_rev.assign(n + 1, {});
        root.assign(n + 1, 0);
    }
    // Directed graph only
    void add_edge(ll u, ll v)
    {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    void dfs1(ll &node)
    {
        visit[node] = true;
        for (auto x : adj[node])
        {
            if (!visit[x])
                dfs1(x);
        }
        topo.push_back(node);
    }
    void dfs2(ll &node, ll par)
    {
        root[node] = par;
        visit[node] = true;
        for (auto x : adj_rev[node])
        {
            if (!visit[x])
                dfs2(x, par);
        }
    }
    void findSCC()
    {
        visit.assign(n + 1, false);
        topo.clear();
        for (ll i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                dfs1(i);
            }
        }
        reverse(all(topo));

        vector<ll> root(n + 1, 0);
        visit.assign(n + 1, false);
        for (auto &x : topo)
        {
            if (!visit[x])
            {
                dfs2(x, x);
            }
        }
    }
    // SCC scc;
    // scc.init(n);
    // scc.add_edge(u,v);
    // scc.findSCC();
};
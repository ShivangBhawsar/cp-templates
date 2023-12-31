void topo_sort(vector<ll> &topo, vector<ll> adj[], ll n)
{
    topo.clear();
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            topodfs(i, adj, visit, topo);
        }
    }
    reverse(all(topo));
}

void topodfs(ll node, vector<ll> adj[], vector<bool> &visited, vector<ll> &topo)
{
    visited[node] = true;
    for (auto x : adj[node])
    {
        if (!visited[x])
            topodfs(x, adj, visited, topo);
    }
    topo.push_back(node);
}
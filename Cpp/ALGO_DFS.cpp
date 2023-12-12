void dfs(ll node, vector<ll> adj[], vector<bool> &visited)
{
    visited[node] = true;
    // do stuff
    for (auto x : adj[node])
    {
        if (!visited[x])
            dfs(x, adj, visited);
    }
}
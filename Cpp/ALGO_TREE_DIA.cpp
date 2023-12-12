// TO FIND MAX DEPTH FROM A NODE IN A TREE
// first element gives distance and second gives node
pair<ll, ll> max_dis_dfs(ll node, vector<ll> adj[], vector<bool> &visit)
{
    visit[node] = true;
    pair<ll, ll> ans = {1, node};
    for (auto &x : adj[node])
    {
        if (!visit[x])
        {
            pair<ll, ll> p = max_dis_dfs(x, adj, visit);
            if (ans.first < p.first + 1)
            {
                ans = {p.first + 1, p.second};
            }
        }
    }
    return ans;
}
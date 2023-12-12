const ll INF = 1e18;

void dijkstra(ll s, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dis, vector<ll> &par)
{
    int n = adj.size();
    dis.assign(n, INF);
    par.assign(n, -1);

    dis[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != dis[v])
            continue;

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (dis[v] + len < dis[to])
            {
                dis[to] = dis[v] + len;
                par[to] = v;
                q.push({dis[to], to});
            }
        }
    }
}
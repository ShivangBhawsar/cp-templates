struct segtree
{
    ll size;
    vector<ll> tree;
    ll neutral_element = 0;

    ll combine(ll a, ll b)
    {
        return a + b;
    }

    void init(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0); //**
    }

    // we are going from lx included to rx not included
    void point_update(ll i, ll val, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] += val; //**
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid)
            point_update(i, val, 2 * x + 1, lx, mid);
        else
            point_update(i, val, 2 * x + 2, mid, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void point_update(ll i, ll val)
    {
        point_update(i, val, 0, 0, size);
    }

    ll query(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return neutral_element;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        ll mid = (lx + rx) / 2;
        ll left = query(l, r, 2 * x + 1, lx, mid);
        ll right = query(l, r, 2 * x + 2, mid, rx);
        return combine(left, right);
    }
    ll query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }
};

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
        for (ll i = 19; i >= 0; --i)
        {
            if (parent[u][i] != 0 && is_ancestor(parent[u][i], v) == false)
                u = parent[u][i];
        }
        return parent[u][0];
    }
};

struct HLD
{
    // Use 0 based indexing
    ll root, n; // Handle the case when n = 1 maybe
    vector<ll> cnt, parent, pathstart;
    vector<bool> isHeavy; // edge from node to parent isHeavy?
    segtree S;
    vector<ll> Sidx;
    LCA lca;

    void init(ll root, vector<vector<ll>> &adj, vector<ll> &val)
    {
        this->root = root;
        this->n = adj.size();
        cnt.assign(n, 0);
        parent.assign(n, 0);
        pathstart.assign(n, 0);
        isHeavy.assign(n, false);
        S.init(n);
        Sidx.assign(n, 0);
        lca.init(root, adj, n);

        this->construct(adj, val);
    }

    void dfs(ll node, vector<vector<ll>> &adj, vector<bool> &visit)
    {
        visit[node] = true;
        cnt[node] = 1;
        for (auto x : adj[node])
        {
            if (!visit[x])
            {
                parent[x] = node;
                dfs(x, adj, visit);
                cnt[node] += cnt[x];
            }
        }
        for (auto x : adj[node])
        {
            if (x != parent[node] && 2 * cnt[x] >= cnt[node])
            {
                isHeavy[x] = true;
            }
        }
    }

    vector<vector<ll>> paths;
    void decompose(ll node, vector<vector<ll>> &adj, ll idx = -1)
    {
        if (idx == -1)
        {
            paths.push_back({node});
            idx = (ll)paths.size() - 1;
        }
        else
        {
            paths[idx].push_back(node);
        }
        for (auto x : adj[node])
        {
            if (x != parent[node])
            {
                if (isHeavy[x])
                {
                    decompose(x, adj, idx);
                }
                else
                {
                    decompose(x, adj);
                }
            }
        }
    }
    void construct(vector<vector<ll>> &adj, vector<ll> &val)
    {
        vector<bool> visit(n, false);
        dfs(root, adj, visit);
        decompose(root, adj, -1);
        ll Scur = 0;
        for (auto &path : paths)
        {
            for (auto &x : path)
            {
                S.point_update(Scur, val[x]);
                Sidx[x] = Scur;
                Scur++;
                pathstart[x] = path[0];
            }
        }
    }
    void update(ll s, ll x)
    {
        S.point_update(Sidx[s], x);
    }

    ll query(ll a, ll b)
    {
        if (lca.is_ancestor(a, b))
        {
            return simplequery(a, b);
        }
        else if (lca.is_ancestor(b, a))
        {
            return simplequery(b, a);
        }
        else
        {
            ll z = lca.lca(a, b);
            return simplequery(z, a) + simplequery(z, b) - S.query(Sidx[z], Sidx[z] + 1);
        }
    }

    ll simplequery(ll p, ll a)
    {
        ll ans = 0;
        ll cur = a;
        while (true)
        {
            ll start = pathstart[cur];
            if (lca.is_ancestor(start, p))
            {
                start = p;
            }
            ans += S.query(Sidx[start], Sidx[cur] + 1);
            cur = parent[start];
            if (start == p)
            {
                break;
            }
        }
        return ans;
    }
};
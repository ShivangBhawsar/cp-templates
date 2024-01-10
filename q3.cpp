/*

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠦⡀⠀⡠⢒⠁⠀⠀⢀⡔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠢⡀⣀⠤⠒⠉⠉
⠀⠀⠀⠀⠀⠀⠀⠀⠁⢁⠀⠀⠀⢀⡼⠋⠠⠀⠀⠀⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⣯⢀⡆⡠⠋⠀⡠⠂⠰⠋⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⢧⣼⠎⠀⡠⠊⠀⢀⠀⠀⢠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⣀
⠀⠀⠀⠀⠀⠀⠀⢰⢃⡴⢁⡔⠊⠀⠀⢠⠞⠀⠀⢸⠀⠀⠀⠀⠀⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿
⠀⠀⠀⠀⠀⠀⢀⣿⠎⢀⡎⠀⠀⠀⠀⠃⠀⠀⠀⢿⠀⠀⠀⠀⠀⠀⣾⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹
⠀⠀⠀⠀⠀⠀⣸⠃⢠⠎⠀⠀⠀⠀⠀⠀⠀⠀⢠⢿⡀⠀⠀⠀⠀⠀⡇⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈
⠀⠀⠀⠀⠀⢀⠏⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⣤⠏⠘⡇⠀⠀⠀⠀⢸⠁⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡜⢀⠏⠀⠀⠀⠀⠀⠀⠀⠀⣰⠯⢄⣀⡇⠀⠀⠀⠀⢸⠀⠱⡀⠹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸
⠀⠀⠀⠀⡜⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠈⡇⢸⠀⠀⠀⢸⠀⠀⠀⠀⠘⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⡜⢀⡼⠁⠀⠀⠀⠀⠀⠀⠀⢰⣏⣠⣀⡀⠀⢸⢾⢧⠀⠀⢸⠀⠀⠀⠀⠠⠜⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡄⢸⡇⠀⠀⠀⠀⠀⢠⣿⠛⠛⣿⣿⣷⣜⣿⠸⡄⠀⢸⠀⠀⠀⠀⠀⢀⡀⠹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡼⢠⣾⠃⡄⠀⠀⠀⢰⣿⡇⢸⣷⡿⠻⣿⣿⡟⠀⢻⡄⢸⠀⠀⠀⠀⠔⣡⣴⣶⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡇⢸⡟⠀⡇⠀⠀⠀⢸⣿⠣⠸⡝⠧⡤⣿⡏⠀⠀⠀⢳⡘⡄⠀⠀⠀⢾⡛⣿⣿⣿⣿⣿⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠁⣾⠃⠀⢳⠀⠀⠀⢸⣿⠀⠀⠉⠒⠒⠋⠀⠀⠀⠀⠀⠙⣇⠀⠀⠀⠘⣿⣯⡀⣸⣿⡇⢈⣷⣄⣠⠀⠀⠀⠀⠀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠉⠀⢰⠸⡄⠀⠀⡞⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠭⠭⠭⠞⠀⠚⢠⣿⣿⣆⠀⠀⠀⢀⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢇⢷⡀⢰⠇⢸⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿⠁⢿⢿⡄⠀⠀⢸⡇⠈⡆⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠘⣇⣾⠀⢸⡇⠳⣄⠀⠀⠀⠀⢲⠤⠤⠤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⣸⣿⣷⠀⠀⡼⡇⢠⠃⠀
⠀⠀⠀⠀⠀⢀⣀⣀⣀⢀⣹⣿⡄⢸⡇⠀⠀⠙⢦⣀⠀⠈⠳⠤⠀⠤⠟⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⠇⠀⣰⣟⣿⣿⣇⠀⡇⣿⡼⠀⠀
⠀⠀⢀⠶⡋⠉⠁⠀⠈⠉⠀⠈⠛⢾⣇⠀⢠⡴⠋⠈⢷⣄⡀⠀⠀⠀⠀⣀⣀⠤⠤⣴⣞⢻⣿⣿⡏⠀⣼⣋⣉⣹⣿⣿⣼⠀⣿⠃⠀⠀
⠀⢀⠃⣸⠁⠀⣼⠀⠀⣸⠁⠀⡄⠀⠹⠛⢻⡄⠀⠀⠈⠙⢮⡑⠊⣉⡽⠋⠀⠀⠀⠼⠉⢿⣿⣿⣀⣼⣿⣿⣿⣿⣿⣿⠋⠀⠁⠀⠀⠀
⠀⠘⢰⠇⠀⢰⡇⠀⢠⡏⠀⢰⠀⠀⡆⢀⡞⠇⠀⠀⠀⠀⠀⢹⠞⠁⠀⠀⠀⠀⠀⡐⣇⠀⠀⢸⠋⠉⠉⠛⠿⣿⣿⣿⡀⠀⠀⠀⠀⠀
⠀⠀⠻⠤⠤⡟⠀⣠⠞⠀⢀⠎⠀⠸⢹⡿⠁⠁⠀⠀⠀⠀⣠⣼⣤⡀⠀⢀⠎⠁⠀⠀⢹⡀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠑⠚⣳⠤⠔⠛⠒⠢⠤⡞⠁⠀⠀⠀⠀⡀⡞⠁⠀⠀⢹⡄⢸⠀⠀⠀⠀⠀⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢇⠀⠀⠀⠀⠀
⢀⠀⠀⣀⣀⣀⣀⣇⣀⠀⢀⣀⡀⢀⠁⠀⠀⠀⠀⠉⠀⠹⡄⠀⢀⡼⠁⠀⠀⠀⠀⠀⠀⠙⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣈⠶⠤⠀⠀⠀⠀⠀⠀⠀
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e9;

vector<vector<pair<ll, ll>>> graph;
vector<ll> score;
vector<ll> dp;

struct DSU
{
    vector<ll> parent;

    DSU(ll n)
    {
        parent = vector<ll>(n, -1);
    }

    // find the leader
    ll find(ll x)
    {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    // check if same componenet
    bool same(ll a, ll b)
    {
        return find(a) == find(b);
    }

    ll size(ll x)
    {
        return -parent[find(x)];
    }

    bool unite(ll a, ll b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (parent[a] > parent[b])
            swap(a, b);

        parent[a] += parent[b];
        parent[b] = a;
        return true;
    }
};

signed main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    DSU dsu = DSU(n);

    graph.resize(n);
    score.resize(n);
    dp.resize(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    vector<vector<pair<ll, ll>>> edges(2e5 + 1);

    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        if (score[x] == score[y])
        {
            dsu.unite(x, y);
        }

        // can go to x to y
        if (score[x] < score[y])
        {
            edges[score[x]].push_back({x, y});
        }
        else if (score[x] > score[y])
        {
            edges[score[y]].push_back({y, x});
        }
    }

    dp[dsu.find(0)] = 1;

    for (auto x : edges)
    {
        for (auto y : x)
        {
            ll leader1 = dsu.find(y.first);
            ll leader2 = dsu.find(y.second);

            if (dp[leader1] == 0)
            {
                continue;
            }

            dp[leader2] = max(dp[leader2], dp[leader1] + 1);
        }
    }

    cout << dp[dsu.find(n - 1)];

    return 0;
}

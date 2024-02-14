vector<vector<ll>> adj;
vector<set<ll> *> subtree;
vector<ll> info;

void smallToLarge(ll root, ll parent = -1)
{
    ll largest = -1;
    vector<ll> children;
    for (ll node : adj[root])
    {
        if (node != parent)
        {
            smallToLarge(node, root);
            children.push_back(node);
            if (largest == -1 || subtree[largest]->size() < subtree[node]->size())
            {
                largest = node;
            }
        }
    }
    if (largest == -1)
    {
        subtree[root] = new set<ll>; // new set for leaf node
    }
    else
    {
        subtree[root] = subtree[largest]; // largest sized child
    }

    for (ll child : children)
    {
        if (child == largest)
            continue;
        for (auto x : *subtree[child])
            subtree[root]->insert(x);
    }

    subtree[root]->insert(root);        //*
    info[root] = subtree[root]->size(); //*
}

// https://codeforces.com/blog/entry/103064
// subtree.resize(n + 1, NULL);
// adj.assign(), info.assign()
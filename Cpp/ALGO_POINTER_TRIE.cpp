struct Node
{
    Node *link[26];
    bool isEnd = false;
    int cnt = 0;
};
struct Trie
{
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *cur = root;
        for (auto x : word)
        {
            if (cur->link[x - 'a'] == NULL)
            {
                Node *newNode = new Node();
                cur->link[x - 'a'] = newNode;
            }
            cur = cur->link[x - 'a'];
            cur->cnt++;
        }
        cur->isEnd = true;
    }

    bool search(string word)
    {
        Node *cur = root;
        for (auto x : word)
        {
            if (cur->link[x - 'a'] == NULL)
            {
                return false;
            }
            cur = cur->link[x - 'a'];
        }
        return cur->isEnd;
    }
};
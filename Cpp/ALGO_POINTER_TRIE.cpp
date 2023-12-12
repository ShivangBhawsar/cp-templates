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

    void remove(string word)
    {
        // memory leak
        if (!search(word))
        {
            return;
        }

        Node *cur = root;
        Node *pre = root;
        for (auto x : word)
        {
            cur = cur->link[x - 'a'];
            cur->cnt--;
            if (cur->cnt == 0)
            {
                pre->link[x - 'a'] = NULL;
                break;
            }
            pre = cur;
        }
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
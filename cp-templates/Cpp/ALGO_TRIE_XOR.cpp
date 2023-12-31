struct Node
{
    Node *link[2];
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
            if (cur->link[x - '0'] == NULL)
            {
                Node *newNode = new Node();
                cur->link[x - '0'] = newNode;
            }
            cur = cur->link[x - '0'];
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
            cur = cur->link[x - '0'];
            cur->cnt--;
            if (cur->cnt == 0)
            {
                pre->link[x - '0'] = NULL;
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
            if (cur->link[x - '0'] == NULL)
            {
                return false;
            }
            cur = cur->link[x - '0'];
        }
        return cur->isEnd;
    }

    string find_min(string word)
    {
        string ans = "";
        Node *cur = root;
        for (auto x : word)
        {
            if (cur->link[x - '0'] == NULL)
            {
                ans.push_back('1');
                if (x == '1')
                {
                    cur = cur->link[0];
                }
                else
                {
                    cur = cur->link[1];
                }
            }
            else
            {
                ans.push_back('0');
                cur = cur->link[x - '0'];
            }
        }
        return ans;
    }
};
struct Trie
{
    vector<vector<int>> trie;

    void init(int n)
    {
        trie.assign(n * 32 + 1, vector<int>(2, -1));
    }
    int next1 = 1;
    void insert(int num)
    {
        vector<int> v1(32);
        for (int i = 31; i >= 0; i--)
        {
            v1[31 - i] = ((num >> i) & 1);
        }
        int z = 0, v = 0;
        while (z < 32)
        {
            if (trie[v][v1[z]] == -1)
            {
                v = trie[v][v1[z++]] = next1++;
            }
            else
            {
                v = trie[v][v1[z++]];
            }
        }
    }
};
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
string escapeQuotesAndNewlines(const string &line)
{
    string escapedLine;
    char prec = '@';
    for (char c : line)
    {
        if (c == '\"')
        {
            escapedLine += "\\\"";
        }
        else if (c == 'n' && prec == '\\')
        {
            escapedLine += "\\n";
        }
        else
        {
            escapedLine += c;
        }
        prec = c;
    }
    return escapedLine;
}

void convertFile(const string &inputFilePath, string &output)
{
    ifstream inputFile(inputFilePath);
    string snippetsFolder = "../.vscode/";
    string outputFolderPath = snippetsFolder + output + ".code-snippets";
    ofstream outputFile(outputFolderPath);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening files!" << endl;
        return;
    }

    stringstream buffer;
    buffer << "{\n\"\": {\n";
    buffer << "  \"prefix\": \"" << output << "\",\n";
    buffer << "  \"body\": [\n";

    string line;
    while (getline(inputFile, line))
    {
        buffer << "    \"" << escapeQuotesAndNewlines(line) << "\",\n";
    }

    buffer.seekp(-2, buffer.cur); // Remove the trailing comma and newline
    buffer << "\n  ],\n";
    buffer << "  \"description\": \"\"\n";
    buffer << "}\n}\n";

    outputFile << buffer.str();

    inputFile.close();
    outputFile.close();

    cout << "Conversion successful!" << endl;
}
int main()
{
    string cppFolder = "./Cpp";

    vector<string> input = {
        "/ALGO_BFS.cpp",
        "/ALGO_BINOMIAL_COEFF.cpp",
        "/ALGO_DFS.cpp",
        "/ALGO_DIJKSTRA.cpp",
        "/ALGO_DIVISORS.cpp",
        "/ALGO_DSU.cpp",
        "/ALGO_FENWICK_TREE.cpp",
        "/ALGO_KMP.cpp",
        "/ALGO_LAZY_SEGTREE.cpp",
        "/ALGO_LCA.cpp",
        "/ALGO_LIS_NLOGN.cpp",
        "/ALGO_MANACHER.cpp",
        "/ALGO_MATRIX_EXPO.cpp",
        "/ALGO_MONOTONIC_STACK.cpp",
        "/ALGO_NCR.cpp",
        "/ALGO_POINTER_TRIE.cpp",
        "/ALGO_POWER.cpp",
        "/ALGO_RANDOM.cpp",
        "/ALGO_SEGTREE.cpp",
        "/ALGO_SIEVE_FACTORIZATION.cpp",
        "/ALGO_SIEVE.cpp",
        "/ALGO_SPARSE_TABLE.cpp",
        "/ALGO_TOPO_SORT.cpp",
        "/ALGO_TREE_DIA.cpp",
        "/ALGO_TRIE_XOR.cpp",
        "/ALGO_VECTOR_TRIE.cpp",
        "/ALGO_HLD_ADD.cpp",
        "/ALGO_HLD_MAX.cpp",
        "/ALGO_MERGESORTTREE.cpp",
        "/ALGO_INT_128.cpp",
        "/ALGO_SCC.cpp",
        "/ALGO_ROLLING_HASH_DOUBLE.cpp",
        "/ALGO_ROLLING_HASH_SINGLE.cpp"};

    vector<string> output = {
        "bfs",
        "binomialCoeff",
        "dfs",
        "dijkstra",
        "divisors",
        "dsu",
        "fenwickTree",
        "kmp",
        "segtreeLazy",
        "lca",
        "lisNlogn",
        "manacher",
        "matrixExpo",
        "monotonicStack",
        "ncr",
        "pointerTrie",
        "power",
        "random",
        "segtree",
        "sieveFactorization",
        "sieve",
        "sparseTable",
        "topoSort",
        "treeDia",
        "trieXor",
        "vectorTrie",
        "hldAdd",
        "hldMax",
        "mergesorttree",
        "int128",
        "scc",
        "rollingHashDouble",
        "rollingHashSingle"};

    int sz = input.size();
    for (int i = 0; i < sz; i++)
    {
        convertFile(cppFolder + input[i], output[i]);
    }
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void convertFile(const std::string &inputFilePath, const std::string &outputFolderPath)
{
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFolderPath);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << "\"\": {\n";
    buffer << "  \"prefix\": \"\",\n";
    buffer << "  \"body\": [\n";

    std::string line;
    while (std::getline(inputFile, line))
    {
        buffer << "    \"" << line << "\",\n";
    }

    buffer.seekp(-2, buffer.cur); // Remove the trailing comma and newline
    buffer << "\n  ],\n";
    buffer << "  \"description\": \"\"\n";
    buffer << "}\n";

    outputFile << buffer.str();

    inputFile.close();
    outputFile.close();

    std::cout << "Conversion successful!" << std::endl;
}
int main()
{
    std::string cppFolder = "./Cpp";
    std::string snippetsFolder = "./Snippets";

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
        "/TEMPLATE.cpp",
    };

    vector<string> output = {
        "/bfs.code-snippets",
        "/binomialCoeff.code-snippets",
        "/dfs.code-snippets",
        "/dijkstra.code-snippets",
        "/divisors.code-snippets",
        "/dsu.code-snippets",
        "/fenwickTree.code-snippets",
        "/kmp.code-snippets",
        "/lazySegtree.code-snippets",
        "/lca.code-snippets",
        "/lisNlogn.code-snippets",
        "/manacher.code-snippets",
        "/monotonicStack.code-snippets",
        "/ncr.code-snippets",
        "/pointerTrie.code-snippets",
        "/power.code-snippets",
        "/random.code-snippets",
        "/segtree.code-snippets",
        "/sieveFactorization.code-snippets",
        "/sieve.code-snippets",
        "/sparseTable.code-snippets",
        "/topoSort.code-snippets",
        "/treeDia.code-snippets",
        "/trieXor.code-snippets",
        "/vectorTrie.code-snippets",
        "/template.code-snippets",
    };

    int sz = input.size();
    for (int i = 0; i < sz; i++)
    {
        convertFile(cppFolder + input[i], snippetsFolder + output[i]);
    }
}
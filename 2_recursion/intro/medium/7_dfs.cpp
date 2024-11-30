#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
    // Private functions
private:
    int V;
    vector<vector<int>> adjList;

    void initGraph(int v)
    {
        this->V = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFSHelper(int startNode, vector<int> &depthFirstSearch, vector<bool> &visited)
    {
        vector<int> list = adjList[startNode];
        visited[startNode] = true;
        depthFirstSearch.push_back(startNode);

        for (int x : list)
            if (!visited[x])
                DFSHelper(x, depthFirstSearch, visited);
    }

    // Public functions
public:
    // Time complexity = O(V+E)
    // Space complexity = O(V)
    vector<int> DFS(const vector<vector<int>> &args, int n, int first)
    {
        initGraph(n);
        vector<int> depthFirstSearch;

        for (vector<int> pair : args)
            addEdge(pair[0], pair[1]);

        vector<bool> visited(args.size(), false);
        DFSHelper(first, depthFirstSearch, visited);

        return depthFirstSearch;
    }
};

int main()
{
    // Example graph
    Solution graph;
    vector<vector<int>> args = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 5}};

    // vector<vector<int>> args = {{1, 2}, {1, 5}, {2, 4}, {4, 5}, {3, 5}};
    vector<int> result = graph.DFS(args, 6, 1);

    printf("DFS traversal: ");
    for (int vertex : result)
        printf("%d ", vertex);

    printf("\n");

    return 0;
}
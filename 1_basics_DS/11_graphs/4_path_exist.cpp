#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Time complexity - O(V+E) - create graph
    // Space complexity - O(V+E) - store graph
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        // Create an adjacencyList
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        return dfs(adjList, start, end, visited);
    }

private:
    // Time complexity - O(V+E) - call stack depth
    // Space complexity - O(V+E) - store graph
    bool dfs(vector<vector<int>> &graph, int node, int end, vector<bool> visited)
    {
        // base case
        if (node == end)
            return true;

        visited[node] = true;

        // Recursive case
        for (auto neighbor : graph[node])
        {
            if (!visited[neighbor])
                return dfs(graph, neighbor, end, visited);
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    cout << sol.validPath(4, edges1, 0, 3) << endl; // true

    vector<vector<int>> edges2 = {{0, 1}, {2, 3}};
    cout << sol.validPath(4, edges2, 0, 3) << endl; // false

    vector<vector<int>> edges3 = {{0, 1}, {3, 4}};
    cout << sol.validPath(5, edges3, 0, 4) << endl; // false
}
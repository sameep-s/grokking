#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        unordered_set<int> nodes_with_incoming;

        for (auto edge : edges)
            nodes_with_incoming.insert(edge[1]);

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (nodes_with_incoming.find(i) == nodes_with_incoming.end())
                result.push_back(i);

        return result;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    for (int vertex : solution.findSmallestSetOfVertices(6, edges1))
        cout << vertex << " ";

    cout << endl; // Expected: 0 3

    vector<vector<int>> edges2 = {{0, 1}, {3, 1}, {1, 2}};
    for (int vertex : solution.findSmallestSetOfVertices(4, edges2))
        cout << vertex << " ";

    cout << endl; // Expected: 0 3

    vector<vector<int>> edges3 = {{2, 0}, {3, 2}};
    for (int vertex : solution.findSmallestSetOfVertices(4, edges3))
        cout << vertex << " ";

    cout << endl; // Expected: 1 3
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int V) : vertices(V), adjList(V) {}; // constructor

    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    void DFS(int start)
    {
        vector<bool> visited = vector(vertices, false);
        stack<int> s;

        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            cout << curr << " ";

            for (int neighbour : adjList[curr])
                if (!visited[neighbour])
                {
                    s.push(neighbour);
                    visited[neighbour] = true;
                }
        }
    }
};

// Depth First Search - DFS
int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "DFS Traversal starting from vertex 0: " << endl;
    g.DFS(0);

    return 0;
}
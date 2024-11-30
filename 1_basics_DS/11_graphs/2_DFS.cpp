#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

    // Time complexity - O(V)
    // Space complexity - O(V)
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

    // Time complexity - O(V), where V is no. of vertices
    // Space complexity - O(V)
    void BFS(int start)
    {
        vector<bool> visited = vector(vertices, false);

        // int stack
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            vector<int> list = adjList[top];

            cout << top << " ";
            for (int x : list)
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
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

    cout << "DFS Traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS Traversal starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
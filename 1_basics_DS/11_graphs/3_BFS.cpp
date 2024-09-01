#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;
    int V;

public:
    // Constructor
    Graph(int vertices)
    {
        adjList.resize(vertices);
        V = vertices;
    }

    void addEdge(int vertex1, int vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    // Time complexity - O(V+E)
    // Space complexity - O(V+E)
    void BFS(int start)
    {
        queue<int> q;
        vector<bool> visited = vector(V, false);

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            for (int neighbour : adjList[curr])
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
        }

        cout << endl;
    }
};

int main()
{
    Graph graph(6); // Create a graph with 6 vertices

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    cout << "Breadth-First Traversal starting from vertex 0:" << endl;
    graph.BFS(0);

    return 0;
}

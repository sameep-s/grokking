#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

// ADT Graph

class Graph
{
private:
    unordered_map<int, vector<int>> adjacencyList;

public:
    // Add vertex
    void add_vertex(int vertex);

    // Remove Vertex
    void remove_vertex(int vertex);

    // Add edge
    void add_edge(int vertex1, int vertex2);

    // Remove edge
    void remove_edge(int vertex1, int vertex2);

    // Get Vertices
    vector<int> get_vertices();

    // Is adjacent
    bool is_adjacent(int vertex1, int vertex2);

    // Get Vertex count
    int get_vertex_count();

    // Get Edge count
    int get_edge_count();

    // Get vector of all edges
    vector<pair<int, int>> get_edges();

    // Get neighbours of a vertex
    vector<int> get_neighbors(int v);
};

// Add vertex
void Graph::add_vertex(int vertex)
{
    if (adjacencyList.find(vertex) != adjacencyList.end())
        adjacencyList[vertex] = vector<int>();
}

// Remove vertex
void Graph::remove_vertex(int vertex)
{
    // If element doesn't exist return
    if (adjacencyList.find(vertex) == adjacencyList.end())
        return;

    // If they exist
    adjacencyList.erase(vertex);
    for (auto &entry : adjacencyList)
    {
        auto &neighbours = entry.second;
        neighbours.erase(remove(neighbours.begin(), neighbours.end(), vertex), neighbours.end());
    }
}

// Add edge
void Graph::add_edge(int vertex1, int vertex2)
{
    adjacencyList[vertex1].push_back(vertex2);
    adjacencyList[vertex2].push_back(vertex1);
}

// Remove edge
void Graph::remove_edge(int vertex1, int vertex2)
{
    // Remove the edge
    auto neighbours1 = adjacencyList[vertex1];
    auto neighbours2 = adjacencyList[vertex2];

    neighbours1.erase(remove(neighbours1.begin(), neighbours1.end(), vertex2), neighbours1.end());
    neighbours2.erase(remove(neighbours2.begin(), neighbours2.end(), vertex1), neighbours2.end());
}

// Get vertices
vector<int> Graph::get_vertices()
{
    // Get list of all vertices in Graph/adjacency list
    vector<int> vertices = vector<int>();

    for (auto &[key, val] : adjacencyList)
        vertices.push_back(key);

    // return vertices
    return vertices;
}

// Get Edges
vector<pair<int, int>> Graph::get_edges()
{
    vector<pair<int, int>> edges;

    for (const pair<const int, vector<int>> &entries : adjacencyList)
    {
        vector<int> neighbours = entries.second;
        const int vertex = entries.first;

        for (int &x : neighbours)
            if (vertex < x)
                edges.push_back(make_pair(vertex, x));
    }

    return edges;
}

// Get neighbours
vector<int> Graph::get_neighbors(int vertex)
{
    // Return the neighbors
    return adjacencyList[vertex];
}

// Is adjacent
bool Graph::is_adjacent(int vertex1, int vertex2)
{
    auto &list = adjacencyList[vertex1];

    return find(list.begin(), list.end(), vertex2) != list.end();
}

// Get vertex count
int Graph::get_vertex_count()
{
    // get the count of vertices
    return adjacencyList.size();
}

// Get edge count
int Graph::get_edge_count()
{
    int count = 0;
    for (auto &entries : adjacencyList)
        count += entries.second.size();

    return count / 2; // because in an undirected graph they are two for one
}

int main()
{
    Graph graph;

    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);
    graph.add_vertex(6);

    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);

    cout << "Vertices: ";
    for (int vertex : graph.get_vertices())
        cout << vertex << " ";

    cout << endl;

    cout << "Edges: ";
    for (auto edge : graph.get_edges())
        cout << "(" << edge.first << ", " << edge.second << ") ";

    cout << endl;

    cout << "Neighbors of vertex 1: ";
    for (int neighbor : graph.get_neighbors(1))
    {
        cout << neighbor << " ";
    }
    cout << endl;

    cout << "Is vertex 1 adjacent to vertex 2? " << boolalpha << graph.is_adjacent(1, 2) << endl;

    graph.remove_edge(1, 2);
    graph.remove_vertex(3);

    cout << "After removing some edges and vertices:" << endl;

    cout << "Vertices: ";
    for (int vertex : graph.get_vertices())
    {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "Edges: ";
    for (auto edge : graph.get_edges())
    {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;

    return 0;
}
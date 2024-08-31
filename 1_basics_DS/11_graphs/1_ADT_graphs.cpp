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

    std::cout << "Vertices: ";
    for (int vertex : graph.get_vertices())
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    std::cout << "Edges: ";
    for (auto edge : graph.get_edges())
    {
        std::cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    std::cout << std::endl;

    std::cout << "Neighbors of vertex 1: ";
    for (int neighbor : graph.get_neighbors(1))
    {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    std::cout << "Is vertex 1 adjacent to vertex 2? " << std::boolalpha << graph.is_adjacent(1, 2) << std::endl;

    graph.remove_edge(1, 2);
    graph.remove_vertex(3);

    std::cout << "After removing some edges and vertices:" << std::endl;

    std::cout << "Vertices: ";
    for (int vertex : graph.get_vertices())
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    std::cout << "Edges: ";
    for (auto edge : graph.get_edges())
    {
        std::cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
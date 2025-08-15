/*
        An adjacency matrix is a 2D array representation of a graph where matrix[i][j] 
        indicates the presence (and possibly weight) of an edge between nodes i and j.
It’s useful for dense graphs and allows O(1) edge lookups, but uses more memory for sparse graphs.
*/
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<int>> adj_matrix;
public: 
    Graph(int num_vertices)
        : num_vertices(num_vertices), adj_matrix(num_vertices+1, vector<int>(num_vertices + 1, 0)) {}

    void add_edge(int from_vertex, int to_vertex, bool is_directed = false, int weight = 1) {
        adj_matrix[from_vertex][to_vertex] = weight;
        if (!is_directed) {
            adj_matrix[to_vertex][from_vertex] = weight;
        }
    }

    void print_adj_matrix() {
        for (int i = 1; i<adj_matrix.size();++i) {
            for(int j = 1; j<adj_matrix[i].size(); ++j) {                    
                cout << adj_matrix[i][j]<< " ";
            }
            cout << "\n";
        }
    }

};


int main() {
    Graph graph(5);

    graph.add_edge(1, 5, true, 2);
    graph.add_edge(2, 4, true, 4);
    graph.add_edge(5, 4, true, 2);
    graph.add_edge(2, 1, true, 4);
    graph.add_edge(5, 3, true, 7);
    graph.add_edge(3, 1, true, 5);
    graph.print_adj_matrix();
    return 0;
}
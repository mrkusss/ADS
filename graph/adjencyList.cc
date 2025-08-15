/*
An adjacency list represents a graph as an array or list of lists, where each node stores a list of its neighbors.
        It’s efficient for sparse graphs, using less memory and allowing easy iteration over neighbors.
*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<pair<int,int>>> adj_list;
public:
    Graph(int num_vertices)
        : num_vertices(num_vertices), adj_list(num_vertices+1) {}

    void add_edge(pair<int,int> vertices, bool is_directed = false, int weight = 0) {
        int from_vertex = vertices.first;
        int to_vertex = vertices.second;

        adj_list[from_vertex].push_back({to_vertex,weight});
        if (!is_directed) {
            adj_list[to_vertex].push_back({from_vertex,weight});
        }
    }

    void print_adj_list() {
        for (int i = 1; i<adj_list.size(); ++i) {
            cout << i << " -> ";
            for (const auto& j: adj_list[i]) {
                if(j.second != 0) {
                    cout << "(" << j.first << ", " << j.second << ")";
                }
                else {
                    cout << j.first;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "from vertex -> (to vertex, weight)" << endl;
    Graph graph(4);

    graph.add_edge({3,1},true,9);
    graph.add_edge({4,2},false,1);
    graph.add_edge({1,2},true,8);
    graph.add_edge({2,3},true,4);
    graph.add_edge({1,4},true,7);

    graph.print_adj_list();

    return 0;
}
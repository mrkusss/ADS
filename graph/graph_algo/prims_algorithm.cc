/*
Prim’s algorithm also finds a minimum spanning tree, but it starts from a single node and grows the MST
        by adding the smallest edge connecting a visited node to an unvisited node.
     It’s commonly used in network routing, circuit design, and infrastructure planning.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <functional>

class Graph {
public:
    Graph(int vertices) : V(vertices), adj_list(vertices) {}

    void add_edge(int u, int v, int weight) {
        adj_list[u].emplace_back(weight, v);
        adj_list[v].emplace_back(weight, u);
    }

    std::vector<std::pair<int, int>> prims_mst(int start) {
        std::vector<bool> in_mst(V, false);
        std::vector<int> key(V, INT_MAX);
        std::vector<int> parent(V, -1);

        // Min-heap: {key, vertex}
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>
        > pq;

        key[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (in_mst[u]) continue;
            in_mst[u] = true;

            for (std::pair<int,int> i : adj_list[u]) {
                if (!in_mst[i.second] && i.first < key[i.second]) {
                    key[i.second] = i.first;
                    parent[i.second] = u;
                    pq.emplace(key[i.second], i.second);
                }
            }
        }

        std::vector<std::pair<int, int>> mst_edges;
        for (int i = 0; i < V; ++i) {
            if (parent[i] != -1) {
                mst_edges.emplace_back(parent[i], i);
            }
        }

        return mst_edges;
    }

private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj_list; // {weight, vertex}
};


int main() 
{
    int count = 7;

    Graph graph(count);

    graph.add_edge(0, 1, 25); 
    graph.add_edge(0, 5, 5);  
    graph.add_edge(1, 2, 9);  
    graph.add_edge(1, 6, 6);  
    graph.add_edge(2, 6, 11); 
    graph.add_edge(2, 3, 10); 
    graph.add_edge(3, 4, 12); 
    graph.add_edge(4, 5, 18); 
    graph.add_edge(5, 6, 16); 

    int start_vertex = 0;
    std::vector<std::pair<int, int>> mst = graph.prims_mst(start_vertex);

    std::cout << "Edges in the MST:" << std::endl;
    for (std::pair<int,int> i : mst) {
        std::cout << i.first << " - " << i.second << std::endl;
    }
 
}
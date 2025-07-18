#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<pair<int, int>>> adj_list;

public:
    // Constructor
    Graph(int num_vertices) : num_vertices(num_vertices), adj_list(num_vertices + 1) {}

    // Method to add an edge
    void add_edge(pair<int, int> vertices, bool is_directed = false, int weight = 0) {
        int from_vertex = vertices.first;
        int to_vertex = vertices.second;

        // Add the edge
        adj_list[from_vertex].push_back({to_vertex, weight});
        if (!is_directed) {
            adj_list[to_vertex].push_back({from_vertex, weight});
        }
    }

    int dijkstra(int src, int dest, vector<int>& path) {
        vector<int> distance(num_vertices+1, INF);
        distance[src] = 0;
        vector<int> predecessor(num_vertices+1);
        predecessor[src] = src;
        vector<bool> processed(num_vertices+1, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // first element is distance and second is the element
        pq.push({0,src});

        while(!pq.empty()) {
            int current_vertex = pq.top().second;
            pq.pop();

            if (processed[current_vertex]) continue;
            processed[current_vertex] = true;

            for (auto u : adj_list[current_vertex]) {
            int b = u.first, w = u.second;
                if ((distance[current_vertex]+w) < distance[b]) {
                    distance[b] = distance[current_vertex]+w;
                    pq.push({distance[b], b});
                    predecessor[b] = current_vertex;
                }
            }

        }

        int curr = dest;
        while(true) {
            path.push_back(curr);
            if (predecessor[curr] == curr) break;
            curr = predecessor[curr];
        }
        reverse(path.begin(), path.end());
        return distance[dest];

    }

};

int main() {
    Graph graph(6);

    graph.add_edge({1, 2}, false, 4);
    graph.add_edge({1, 3}, false, 4);
    graph.add_edge({2, 3}, false, 2);
    graph.add_edge({3, 4}, false, 3);
    graph.add_edge({3, 5}, false, 1);
    graph.add_edge({3, 6}, false, 6);
    graph.add_edge({4, 6}, false, 2);
    graph.add_edge({5, 6}, false, 3);

    int src = 1;
    int dest = 6;
    vector<int> path;
    int distance = graph.dijkstra(src, dest, path);

    cout << distance << "\n";
    for(auto item: path) {
        cout << item << " ";
    }

    return 0;
}
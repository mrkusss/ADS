/*
    Topological sort is used to linearly order the nodes of a directed acyclic graph (DAG) 
                such that for every directed edge u → v, u comes before v. 
It’s used in task scheduling, build systems, course prerequisite planning, and dependency resolution.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<int>> adj_list;
public:
    Graph(int num_vertices) : num_vertices(num_vertices), adj_list(num_vertices + 1) {}

    void add_directed_edge(pair<int, int> vertices) {
        int from_vertex = vertices.first;
        int to_vertex = vertices.second;

        adj_list[from_vertex].push_back(to_vertex);
    }

    void add_directed_edges(vector<pair<int, int>> edges) {
        for(const auto edge: edges) {
            add_directed_edge(edge);
        }
    }

    vector<int> topological_sort() {
        vector<int> result;
        vector<int> indegrees(num_vertices+1);
        queue<int> q;

        for (int i = 1; i<=num_vertices;++i) {
            for (auto node: adj_list[i]) {
                ++indegrees[node];
            }
        }

        for (int i = 1; i<=num_vertices;++i) {
            if(!indegrees[i]) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int current_vertex = q.front();
            result.push_back(current_vertex);
            q.pop();

            for (auto degrees_int : adj_list[current_vertex]) {
                --indegrees[degrees_int];
                if (!indegrees[degrees_int]) {
                    q.push(degrees_int);
                }
            }

        }
        return result;
    }
};

int main() {
    Graph graph(5);

    vector<pair<int, int>> edges {
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 5},
        {3, 4},
        {5, 1},
        {5, 3}
    };

    graph.add_directed_edges(edges);

    vector<int> ordering = graph.topological_sort();

    for(auto item: ordering) {
        cout << item << " ";
    }

    return 0;
}
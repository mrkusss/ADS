#include <iostream>
#include <unordered_set>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int number_ver;
    vector<vector<int>> adj_list;
 public:
    Graph(int number_ver)
        : number_ver(number_ver), adj_list(number_ver+1) {}

    void add_edge(pair<int,int> vertecies) {
        int from_vertex = vertecies.first;
        int to_vertex = vertecies.second;

        adj_list[from_vertex].push_back(to_vertex);
        adj_list[to_vertex].push_back(from_vertex);
    }

    vector<int> dfs_traversal(int start_index) {
        stack<int> to_visit;
        vector<int> traversal_seq;
        unordered_set<int> visited;
        to_visit.push(start_index);

        while(!to_visit.empty()) {
            int current_index = to_visit.top();
            to_visit.pop();

            if (!visited.count(current_index)) {
                traversal_seq.push_back(current_index);
                visited.insert(current_index);

                for (auto neighbour : adj_list[current_index]) {
                    if (!visited.count(neighbour)) {
                        to_visit.push(neighbour);
                    }
                }
            }
        }
        return traversal_seq;
    }

   vector<int> bfs_traversal(int start_index) {
        queue<int> q;
        vector<int> traversal_seq;
        unordered_set<int> visited;
        q.push(start_index);

        while(!q.empty()) {
            int current_index = q.front();
            q.pop();

            if (!visited.count(current_index)) {
                traversal_seq.push_back(current_index);
                visited.insert(current_index);

                for (auto neighbour : adj_list[current_index]) {
                    if (!visited.count(neighbour)) {
                        q.push(neighbour);
                    }
                }
            }
        }
        return traversal_seq;
   }
    void print_graph() {
        for (int i = 1;  i < adj_list.size(); ++i) {
            cout << i << " -> " << "( ";
            for (auto j : adj_list[i]) {
                cout << j << " ";
            }
            cout << ")" << endl;
        }
    }
};

int main() {
    Graph graph(5);

    graph.add_edge({2,4});
    graph.add_edge({2,3});
    graph.add_edge({3,5});
    graph.add_edge({1,2});
    graph.add_edge({4,1});

    graph.print_graph();

    vector<int> dfsTraversal = graph.dfs_traversal(1);
    cout << "DFS Traversal: ";
    for (auto i : dfsTraversal) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> bfsTraversal = graph.bfs_traversal(1);
    cout << "BFS Traversal: ";
    for (auto i : bfsTraversal) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge 
{
public: 
    int src, dest, weight;

    Edge(int s,int d,int w): src(s), dest(d), weight(w) {}
};

class UnionFind 
{
private:
    vector<int> parents, rank;
public:    
    UnionFind(int num): parents(num), rank(num, 0) 
    {
        for (int i = 0; i < num; ++i ) {
            parents[i] = i;
        }
    } 

    int find(int x) 
    {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unite(int u, int v ) 
    {
        int parent_u = find(u);
        int parent_v = find(v);

        if (parent_u != parent_v) {
            if (rank[parent_u] > rank[parent_v]) {
                parents[parent_v] = parent_u;
            }
            else if (rank[parent_u] < rank[parent_v]) {
                parents[parent_u] = parent_v;
            }
            else {
                parents[parent_v] = parent_u;
                rank[parent_u]++;
            }
        }
    }
};

bool compare(Edge a, Edge b) 
{
    return a.weight < b.weight;
}

vector<Edge> kruskal_algorithm(vector<Edge> edges, int num_vertices) 
{
    sort(edges.begin(), edges.end(), compare);

    vector<Edge> mst;

    UnionFind uf(num_vertices);

    for (Edge edge : edges) {
        int s = edge.src;
        int d = edge.dest;

        int parent_s = uf.find(s);
        int parent_d = uf.find(d);

        if (parent_d != parent_s) {
            mst.push_back(edge);
            uf.unite(parent_d,parent_s);
        }

    }

    return mst;
}

int main() 
{
    int vertices_num = 5;

    vector<Edge> edges = {
        Edge(0,3,5),
        Edge(0,2,6),
        Edge(0,1,3),
        Edge(1,3,16)
    };

    vector<Edge> mst = kruskal_algorithm(edges, vertices_num);

    cout << "Edges in the MST:" << endl;
    for (auto& edge : mst) {
        cout << edge.src << " - " << edge.dest <<endl;
    }
}
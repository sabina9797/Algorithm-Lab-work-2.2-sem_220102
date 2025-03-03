#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); 
    DSU dsu(n);
    vector<Edge> mst;

    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) { 
            dsu.unite(e.u, e.v);
            mst.push_back(e);
        }
    }
    return mst;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<Edge> edges(m);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    vector<Edge> mst = kruskalMST(n, edges);

    cout << "Minimum Spanning Tree edges:" << endl;
    for (Edge e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, minIndex = -1;
    
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    int totalWeight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false); 

    key[0] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); 
        mstSet[u] = true; 

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;  // Since it's an undirected graph
    }

    primMST(graph, V);

    return 0;
}

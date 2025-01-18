#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Find function for DSU
int findParent(int node, vector<int>& parent) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node], parent);
}

// Union function for DSU
void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n, m; // n = nodes, m = edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<Edge> edges(m);

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // DSU initialization
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (const auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mstWeight += edge.weight;
            mstEdges.push_back(edge);
            unionNodes(edge.u, edge.v, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
    cout << "Edges in MST:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }

    return 0;
}

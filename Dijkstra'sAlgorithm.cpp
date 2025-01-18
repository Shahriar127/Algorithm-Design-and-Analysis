#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, int src, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &[v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; i++) cout << "Distance to " << i << ": " << dist[i] << "\n";
}

int main() {
    int V, E, src;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> src;
    dijkstra(V, src, adj);
    return 0;
}

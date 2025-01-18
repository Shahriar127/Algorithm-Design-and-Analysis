#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int primMST(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int cost = 0;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        cost += w;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }
    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int minimum_cost = primMST(graph);
    cout << "Minimum Cost of MST: " << minimum_cost << endl;
    return 0;
}

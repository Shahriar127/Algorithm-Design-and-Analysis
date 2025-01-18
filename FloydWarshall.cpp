#include <bits/stdc++.h>
using namespace std;
#define INF 1e9 // Infinity

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {          // Intermediate node
        for (int i = 0; i < n; i++) {      // Source node
            for (int j = 0; j < n; j++) {  // Destination node
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Input graph
    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    // Distance to self is 0
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    // Run Floyd-Warshall Algorithm
    floydWarshall(dist, n);

    return 0;
}


/*Enter number of nodes and edges: 4 4
Enter edges (u, v, weight):
0 1 5
0 3 10
1 2 3
2 3 1

Shortest distance matrix:
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0
*/
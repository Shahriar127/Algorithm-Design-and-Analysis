#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int totalCost(vector<vector<int>> &cost, vector<bool> &visited, int pos, int n, int count) {
    if (count == n) {
        return cost[pos][0]; // Return to the starting city
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // If city `i` is not visited
            visited[i] = true;
            ans = min(ans, cost[pos][i] + totalCost(cost, visited, i, n, count + 1));
            visited[i] = false; // Backtrack
        }
    }

    return ans;
}

int tsp(vector<vector<int>> &cost) {
    int n = cost.size();
    vector<bool> visited(n, false);
    visited[0] = true; // Start from the first city
    return totalCost(cost, visited, 0, n, 1);  
}

int main() {
    vector<vector<int>> cost = {{0, 10, 15, 20}, 
                                {10, 0, 35, 25}, 
                                {15, 35, 0, 30}, 
                                {20, 25, 30, 0}};
    int res = tsp(cost);
    cout << "Minimum cost: " << res << endl;
    return 0;
}

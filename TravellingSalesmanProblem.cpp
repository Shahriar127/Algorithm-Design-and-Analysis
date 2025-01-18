#include <bits/stdc++.h>
using namespace std;

int totalCost(int mask, int pos, int n, vector<vector<int>> &cost) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, cost[pos][i] + totalCost((mask | (1 << i)), i, n, cost));
        }
    }

    return ans;
}

int tsp(vector<vector<int>> &cost) {
    int n = cost.size();
    return totalCost(1, 0, n, cost);  
}

int main() {
    vector<vector<int>> cost = {{0, 10, 15, 20}, 
                                {10, 0, 35, 25}, 
                                {15, 35, 0, 30}, 
                                {20, 25, 30, 0}};
    int res = tsp(cost);
    cout << res << endl;
    return 0;
}

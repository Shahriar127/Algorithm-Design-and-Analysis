#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                int include = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack(W, weights, values, n) << endl;
    return 0;
}

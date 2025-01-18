#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& dims, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> dims(n);
    for (int i = 0; i < n; i++) {
        cin >> dims[i];
    }
    cout << matrixChainMultiplication(dims, n) << endl;
    return 0;
}

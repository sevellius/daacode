#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int W) {
    int n = coins.size();

    // DP table
    vector<vector<int>> a(n + 1, vector<int>(W + 1, 0));

    // Base case
    for (int i = 0; i <= n; i++)
        a[i][0] = 0;

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {

            // If coin is greater than value
            if (coins[i - 1] > j) {
                a[i][j] = a[i - 1][j];
            }
            else {
                // Take min of:
                // 1. Not taking coin
                // 2. Taking coin (stay in same row i)
                a[i][j] = min(
                    a[i - 1][j],
                    1 + a[i][j - coins[i - 1]]
                );
            }
        }
    }

    return a[n][W];
}

int main() {
    vector<int> coins = {1, 5, 6, 9};
    int W = 10;

    cout << "Minimum coins required: "
         << minCoins(coins, W);

    return 0;
}

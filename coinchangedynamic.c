#include <stdio.h>
#include <limits.h>

void coinChangeDP(int coins[], int m, int V) {
    int dp[V + 1];
    dp[0] = 0; // Base case

    // Initialize dp array
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX; // Set to maximum value
    }

    // Fill dp[] array using the above formula
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    if (dp[V] == INT_MAX) {
        printf("Change cannot be made exactly.\n");
    } else {
        printf("Minimum coins required: %d\n", dp[V]);
    }
}

int main() {
    int coins[] = {25, 10, 5, 1}; // Example denominations
    int V = 63;                   // Total amount
    int m = sizeof(coins) / sizeof(coins[0]);
    
    coinChangeDP(coins, m, V);
    return 0;
}

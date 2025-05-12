#include <stdio.h>

void coinChangeGreedy(int coins[], int m, int V) {
    int coinCount = 0;

    printf("Using greedy approach:\n");
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            int numCoins = V / coins[i];
            coinCount += numCoins;
            V -= numCoins * coins[i];
            printf("%d coins of denomination %d\n", numCoins, coins[i]);
        }
    }

    if (V > 0) {
        printf("Change cannot be made exactly.\n");
    } else {
        printf("Total coins used: %d\n", coinCount);
    }
}

int main() {
    int coins[] = {25, 10, 5, 1}; // Example denominations
    int V = 63;                   // Total amount
    int m = sizeof(coins) / sizeof(coins[0]);
    
    coinChangeGreedy(coins, m, V);
    return 0;
}

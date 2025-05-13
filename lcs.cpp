#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the length of LCS
int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) { // If characters match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else { // If characters do not match
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS will be in dp[m][n]
    return dp[m][n];
}

// Function to print the LCS
void printLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;  // Add the character to the LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "The LCS is: " << lcs << endl;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABB";

    cout << "Length of LCS: " << LCS(X, Y) << endl;
    printLCS(X, Y);

    return 0;
}

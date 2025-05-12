#include <stdio.h>
#include <string.h>

// Function to preprocess the pattern
void computeLPSArray(char* pattern, int m, int* lps) {
    int length = 0; // length of previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // Build the LPS array
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern searching function
void KMPSearch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m]; // Longest Prefix Suffix array

    computeLPSArray(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABCCABABCA";
    char pattern[] = "ABCA";

    KMPSearch(text, pattern);
    return 0;
}

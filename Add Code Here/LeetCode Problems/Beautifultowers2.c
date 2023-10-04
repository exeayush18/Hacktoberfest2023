#include <stdio.h>

int maxBuilding(int n, int* maxHeights, int maxHeightsSize) {
    // Create an array to store the maximum heights achievable at each index.
    int dp[n];
    
    // Initialize the left and right boundaries.
    dp[0] = maxHeights[0];
    dp[n - 1] = n - 1;
    
    // Forward pass: calculate the maximum heights from left to right.
    for (int i = 1; i < n; i++) {
        dp[i] = fmin(dp[i - 1] + maxHeights[i], maxHeights[i]);
    }
    
    // Backward pass: calculate the maximum heights from right to left.
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = fmin(dp[i], dp[i + 1] + maxHeights[i]);
    }
    
    // Calculate the maximum possible sum of heights.
    int maxSum = 0;
    for (int i = 0; i < n - 1; i++) {
        int diff = dp[i + 1] - dp[i];
        int half = (maxHeights[i + 1] - maxHeights[i] - diff) / 2;
        maxSum = fmax(maxSum, maxHeights[i] + half + dp[i]);
    }
    
    return maxSum;
}

int main() {
    int maxHeights[] = {4, 2, 3, 1};
    int n = sizeof(maxHeights) / sizeof(maxHeights[0]);
    int result = maxBuilding(n, maxHeights, n);
    printf("Maximum possible sum of heights: %d\n", result);
    return 0;
}

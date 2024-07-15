const int MAX_WEIGHT = 10000; // Adjust based on problem constraints

int knapsack(vector<int>& weights,vector<int>& values, int W) {
    int n = weights.size();
    bitset<MAX_WEIGHT + 1> dp;
    dp[0] = 1; // Initialize with sum 0 achievable
    for (int i = 0; i < n; ++i) {
        dp |= dp << weights[i]; // Update achievable sums with the current item
    }

    int max_value = 0;
    for (int weight = 0; weight <= W; ++weight) {
        if (dp[weight]) {
            max_value = std::max(max_value, weight);
        }
    }
    return max_value;
}

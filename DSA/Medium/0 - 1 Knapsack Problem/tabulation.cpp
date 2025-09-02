class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt){
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for(int weight = wt[0]; weight <= W; weight++) {
            dp[0][weight] = val[0];
        }
        
        for(int index = 1; index < n; index++) {
            for(int weight = 0; weight <= W; weight++) {
                // Exclude the current item. The profit is the same as the previous state.
                int exclude = dp[index - 1][weight];

                // Include the current item (if it fits).
                int include = 0;
                if(wt[index] <= weight) {
                    include = val[index] + dp[index - 1][weight - wt[index]];
                }

                dp[index][weight] = max(include, exclude);
            }
        }

        return dp[n - 1][W];
    }
};

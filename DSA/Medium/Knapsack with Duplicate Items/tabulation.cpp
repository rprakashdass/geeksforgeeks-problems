// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        
        for(int weight = wt[0];weight <= capacity;weight++){
            // how many times we can fit val[0] into the sack
            dp[0][weight] = (int)(weight/wt[0]) * val[0];
        }
        
        for(int index = 1;index < n;index++){
            for(int weight = 0;weight <= capacity;weight++){
                int exclude = dp[index-1][weight];
                int include = 0;
                if(wt[index] <= weight) {
                    include = val[index] + dp[index][weight-wt[index]];
                }
                dp[index][weight] = max(include, exclude);
            }
        }
        
        return dp[n-1][capacity];
    }
};

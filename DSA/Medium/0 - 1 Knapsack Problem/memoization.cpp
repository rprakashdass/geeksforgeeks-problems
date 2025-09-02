class Solution {
  public:
    int findMaxProfit(vector<vector<int>> &memo, vector<int>& val, vector<int>& wt, int capacity, int i){
        if(i < 0 || capacity <= 0) return 0;
        if(memo[i][capacity] != -1) return memo[i][capacity];
        int include = 0, exclude = 0;
        // pick
        if(capacity - wt[i] >= 0) {
            include = findMaxProfit(memo, val, wt,  capacity - wt[i], i-1) + val[i];
        }

        // not pick
        exclude = findMaxProfit(memo, val, wt, capacity, i-1);

        return memo[i][capacity] = max(include, exclude);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt){
        int n = val.size();
        vector<vector<int>> memo(n, vector<int>(W+1, -1));
        return findMaxProfit(memo, val, wt, W, n-1);
    }
};

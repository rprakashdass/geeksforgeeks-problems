// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution {
  private:
    int recur(vector<int>& weight, vector<int>& profit, vector<vector<int>>& memo, int capacity, int index){
        if(index == 0){
            return (weight[index] <= capacity) ? profit[index] : 0;
        }
        
        if(memo[index][capacity] != -1) return memo[index][capacity];
  
        int take = 0;
        if(weight[index] <= capacity){
            take = profit[index] + recur(weight, profit, memo, capacity - weight[index], index-1);
        }
        int notTake = recur(weight, profit, memo, capacity, index-1);

        return memo[index][capacity] = max(take, notTake);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> memo(n, vector<int>(capacity+1, -1));
        return recur(wt, val, memo, capacity, n-1);
    }
};

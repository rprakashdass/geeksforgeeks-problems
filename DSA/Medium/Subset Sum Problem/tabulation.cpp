class Solution{   
public:
    bool isSubsetSum(vector<int>ar, int k){
        int n = ar.size();
        vector<vector<bool>> dp(n, vector<bool> (k+1, false));
        
        // can make 0 by excluding numbers from i = 0 -> i = n-1
        for(int arIndx = 0;arIndx < n;arIndx++) dp[arIndx][0] = true;
        // first element can only make one target
        if(ar[0] <= k) dp[0][ar[0]] = true;
        
        for(int index = 1;index < n;index++) {
            for(int target = 1;target <= k;target++) {
                bool exclude = dp[index-1][target];
                bool include = false;
                if(ar[index] <= target) {
                    include = dp[index-1][target-ar[index]];
                }
                dp[index][target] = (include || exclude);
            }
        }
        
        return dp[n-1][k];
    }
};

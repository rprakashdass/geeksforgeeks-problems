class Solution{   
public:
    bool isSubset(vector<int> &ar, vector<vector<int>> &dp, int target, int index) {
        if(target == 0) return true;
        if(index == 0) return (ar[0] == target);
        if(dp[index][target] != -1) return dp[index][target];
        
        bool include = false;
        if(target - ar[index] >= 0)
            include = isSubset(ar, dp, target - ar[index], index-1);

        bool exclude = isSubset(ar, dp, target, index-1);

        return dp[index][target] = (include || exclude);
    }
    bool isSubsetSum(vector<int>arr, int target){
        vector<vector<int>> dp(arr.size(), vector<int> (target+1, -1));
        return isSubset(arr, dp, target, arr.size()-1);
    }
};

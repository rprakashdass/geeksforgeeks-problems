// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int maxLen = 0, sum = 0;
        for(int i = 0;i < arr.size();i++){
            sum += arr[i];
            if(sum == k) maxLen = max(maxLen, i + 1);
            int need = sum - k;
            if(mp.find(need) != mp.end()){
                maxLen = max(maxLen, i - mp[need]);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxLen;
    }
};

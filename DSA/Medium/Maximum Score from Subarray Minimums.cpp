// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int n = arr.size(), maxSum = 0;
        for(int i = 0;i < n-1;i++){
            maxSum = max(maxSum, arr[i] + arr[i+1]);
        }
        return maxSum;
    }
};

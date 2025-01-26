// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        int maxm = 0;
        vector<int> leader;
        for(int i = n-1;i >= 0;i--) {
            if(arr[i] >= maxm) {
                leader.insert(leader.begin(), arr[i]);
                maxm = arr[i];
            }
        }
        return leader;
    }
};

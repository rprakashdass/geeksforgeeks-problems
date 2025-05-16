class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int left = 0, right = arr.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] <= x){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};

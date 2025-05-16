https://www.geeksforgeeks.org/problems/implement-lower-bound/1
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1, result = arr.size();
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};

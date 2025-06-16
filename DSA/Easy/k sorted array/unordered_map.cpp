// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        unordered_map<int, int> indexCounter;
        for(int i = 0;i < n;i++) {
            indexCounter[arr[i]] = i; 
        }
        sort(arr, arr + n);
        for(int j = 0;j < n;j++) {
            int i = indexCounter[arr[j]];
            if(abs(i - j) > k) return "No";
        }
        return "Yes";
    }
};

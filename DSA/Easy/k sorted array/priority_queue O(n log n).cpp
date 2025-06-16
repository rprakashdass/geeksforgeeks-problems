// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        
        unordered_map<int, int> originalIndex;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0;i < n;i++) {
            originalIndex[arr[i]] = i;
            minHeap.push(make_pair(arr[i], i));
        }
        int j = 0;
        while(!minHeap.empty()) {
            int i = originalIndex[minHeap.top().first];
            minHeap.pop();
            if(abs(i - j) > k) return "No";
            j++;
        }
        return "Yes";
    }
};

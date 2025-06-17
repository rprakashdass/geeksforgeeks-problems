// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1
// User function Template for C++

class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr, int N) {
        map<int, int> mp;
        for(int num: arr) {
            mp[num] = 0;
        }
        int i = 0;
        for(auto ele : mp) {
            int num = ele.first;
            mp[num] = ++i;
        }
        for(int i = 0;i < N;i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};

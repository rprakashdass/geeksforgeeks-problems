// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        set<int> unio;
        while(i < n && j < m){
            if(a[i] == b[j]){
                unio.insert(a[i]);
                i++, j++;
            }
            else if(a[i] < a[j]) unio.insert(a[i++]);
            else unio.insert(b[j++]);
        }
        while(i < n) {
            unio.insert(a[i++]);
        }
        while(j < m) {
            unio.insert(b[j++]);
        }

        vector<int> ans(unio.begin(), unio.end());
        return ans;
    }
};

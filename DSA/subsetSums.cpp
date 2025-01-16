class Solution {
  private:
    void getSubsetsSum(vector<int>& ar, vector<int>& result, int ind, int sum){
        if(ind == ar.size()){
            result.push_back(sum);
            return;
        }
        sum += ar[ind];
        getSubsetsSum(ar, result, ind+1, sum);
        sum -= ar[ind];
        getSubsetsSum(ar, result, ind+1, sum);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> result;
        getSubsetsSum(arr, result, 0, 0);
        return result;
    }
};

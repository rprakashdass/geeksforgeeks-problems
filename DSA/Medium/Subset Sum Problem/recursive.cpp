class Solution{   
public:
    bool isSubset(vector<int> &ar, int target, int index) {
        if(target == 0) return true;
        if(index == ar.size()) return false;
        target -= ar[index];
        if(target >= 0 && isSubset(ar, target, index+1)) return true;
        target += ar[index];
        if(isSubset(ar, target, index+1)) return true;
        return false;
    }
    bool isSubsetSum(vector<int>arr, int target){
        return isSubset(arr, target, 0);
    }
};

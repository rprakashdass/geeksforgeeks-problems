class Solution {
  private:
    void merge(vector<int>& arr, int l, int mid, int r){
        vector<int> temp;
        int leftptr = l, rightptr = mid+1;
        while(leftptr <= mid && rightptr <= r){
            if(arr[leftptr] <= arr[rightptr]){
                temp.push_back(arr[leftptr++]);
            }
            else if(arr[leftptr] > arr[rightptr]){
                temp.push_back(arr[rightptr++]);
            }
        }
        while(leftptr <= mid){
            temp.push_back(arr[leftptr++]);
        }
        while(rightptr <= r){
            temp.push_back(arr[rightptr++]);
        }
        
        for(int i = l;i <= r;i++){
            arr[i] = temp[i - l];
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

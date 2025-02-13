class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        // code here

        sort(A.begin(), A.end(), greater<>());
        sort(B.begin(), B.end(), greater<>());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> indices;
        vector<int> result;
        
        pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));
        indices.insert(make_pair(0, 0));
        for(int i = 0;i < k;i++) {
            int newi = pq.top().second.first;
            int newj = pq.top().second.second;
            result.push_back(pq.top().first);
            pq.pop();
            
            int sum = A[newi] + B[newj+1];
            pair<int, int> curIndex = make_pair(newi, newj+1);
            if(indices.find(curIndex) == indices.end()){
                pq.push(make_pair(sum, make_pair(newi, newj+1)));
                indices.insert(curIndex);
            }
            
            sum = A[newi+1] + B[newj];
            curIndex = make_pair(newi+1, newj);
            if(indices.find(curIndex) == indices.end()){
                pq.push(make_pair(sum, make_pair(newi+1, newj)));
                indices.insert(curIndex);
            }
            
        }

        return result;
    }
};

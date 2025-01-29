class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int source){
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjNode: adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> adjLis(V);
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(adj[i][j] && i != j){
                    adjLis[i].push_back(j);
                }          
            }
        }
        vector<bool> visited(V, false);
        int cnt = 0;
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                bfs(adjLis, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};

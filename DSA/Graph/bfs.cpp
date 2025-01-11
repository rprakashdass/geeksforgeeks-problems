class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> bfs;
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            
            for(auto vertex: adj[node]){
                if(!visited[vertex]){
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }
        
        return bfs;
    }
};

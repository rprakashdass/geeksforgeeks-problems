// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  private:
    void dfs(vector<vector<int>>& adj, vector<int>& dfsL, vector<bool>& visited, int source){
        visited[source] = true;
        dfsL.push_back(source);
        
        for(auto adjNode: adj[source]){
            if(!visited[adjNode]){
                dfs(adj, dfsL, visited, adjNode);
            }
        }
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> dfsL;
        vector<bool> visited(n, false);
        int source = 0;
        dfs(adj, dfsL, visited, source);
        return dfsL;
    }
};

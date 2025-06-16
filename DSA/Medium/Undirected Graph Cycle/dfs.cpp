// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, int node, int parent){
        visited[node] = true;
        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                if(dfs(adjList, visited, neighbour, node)) {
                    return true;
                }
            } else if(neighbour != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(V, false);
        for(int i = 0;i < V;i++){
            if(!visited[i]) {
                if(dfs(adjList, visited, i, -1)) return true;
            }
        }
        return false;
    }
};

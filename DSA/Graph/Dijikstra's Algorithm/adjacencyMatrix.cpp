// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;
                
                if(dist[adjNode] > adjDist + curDist){
                    dist[adjNode] = adjDist + curDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        
        return dist;
        
    }
};

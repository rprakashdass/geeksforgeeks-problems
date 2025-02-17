https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(!root) return {};
        vector<int> result;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                auto nodePair = q.front();
                q.pop();
                
                int level = nodePair.second;
                Node* node = nodePair.first;
                
                if(mp.find(level) == mp.end()){
                    mp[level] = node->data;
                }
                
                if(node->left){
                    q.push({node->left, level-1});
                }
                if(node->right) {
                    q.push({node->right, level+1});
                }
            }
        }
        for(auto it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};

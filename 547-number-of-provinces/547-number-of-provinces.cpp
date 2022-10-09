class Solution {
    void dfs(vector<vector<int>> &adj,int i,vector<bool> &vis){
        vis[i] = true;
        for(auto it: adj[i]){
            if(!vis[it]) dfs(adj,it,vis);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); 
        vector<bool> vis(V,false);
        
        vector<vector<int>> adj(V);
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected[0].size();j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                ans++;
                dfs(adj,i,vis);
            }
        }
        
        return ans;
    }
};
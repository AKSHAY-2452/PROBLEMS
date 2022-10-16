//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //creating adjacency list
        vector<pair<int,int>> adj[n+1]; // 1 index
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            int curr_node = pq.top().second;
            int curr_dist = pq.top().first;
            pq.pop();
            for(auto it: adj[curr_node]){
                int edge_dist = it.second;
                int new_node  = it.first;
                
                if(dist[new_node] > edge_dist+curr_dist){
                   dist[new_node] = edge_dist+curr_dist; 
                   pq.push({dist[new_node],new_node});
                   parent[new_node] = curr_node;
                }
            }
        }
        
        vector<int> ans;
        
        int i = n;
        while(parent[i]!=i){
            ans.push_back(i);
            i = parent[i];
        }
        if(i == n) return {-1};
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
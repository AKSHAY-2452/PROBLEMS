//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    class DisjointSet{
      public:
        vector<int> parent,rank;
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
        }
        
        int findUParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionByRank(int u,int v,int &temp){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            
            if(ulp_u == ulp_v) return;
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
                temp--;
                return;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
                temp--;
                return;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
                temp--;return;
            }
        }
    };
  public:
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int k = operators.size();
        vector<vector<int>> adj(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        vector<int> ans;
        int tempo = 0;
        for(auto it: operators){
            if(adj[it[0]][it[1]] == 1){
                ans.push_back(tempo);
                continue;
            }
            adj[it[0]][it[1]] = 1;
            int temp = it[0]*m+it[1];
            tempo++;
            if(it[0]-1 >= 0 && adj[it[0]-1][it[1]]) ds.unionByRank(temp,(it[0]-1)*m+it[1],tempo);
            if(it[1]+1 < m && adj[it[0]][it[1]+1])  ds.unionByRank(temp,(it[0])*m+it[1]+1,tempo);
            if(it[1]-1 >= 0 && adj[it[0]][it[1]-1]) ds.unionByRank(temp,(it[0])*m+it[1]-1,tempo);
            if(it[0]+1 < n && adj[it[0]+1][it[1]]) ds.unionByRank(temp,(it[0]+1)*m+it[1],tempo);
            ans.push_back(tempo);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
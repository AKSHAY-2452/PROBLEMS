//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        queue<pair<int,pair<int,int>>> q;
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        
        int dr[4] ={-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int dis = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            if(r == destination.first && c == destination.second) return dis;
            for(int i = 0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr >=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] == 1 && 1+dis < dist[nr][nc]){
                    dist[nr][nc] = 1+dis;
                    if(nr == destination.first && nc == destination.second) return dist[nr][nc];
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
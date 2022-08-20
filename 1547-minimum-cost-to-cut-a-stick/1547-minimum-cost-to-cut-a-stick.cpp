class Solution {
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;//base case
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i;k<=j;k++){
            int temp = (cuts[j+1] - cuts[i-1]) + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp);
            mini = min(mini,temp);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        
        int z = cuts.size()-2;
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(cuts,1,z,dp);
    }
};
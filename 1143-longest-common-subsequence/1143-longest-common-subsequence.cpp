class Solution {
    int solve(string a,string b,int i,int j){
        //base case
        if(i == a.length() || j == b.length()) return 0;
        
        //recursive calls
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a,b,i+1,j+1);
        }
        else{
            ans = max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }
        
        return ans;
    }
    
    int solveMemo(string a,string b,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i == a.length() || j == b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        //recursive calls
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveMemo(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(solveMemo(a,b,i+1,j,dp),solveMemo(a,b,i,j+1,dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int solveTab(string a,string b){
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
        //base case also covered in above case so no need to write base case
        
        //in memo  i -> 0 to text1.length()-1 and j -> 0 to text2.length()-1 here reverse that
        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
        
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //return solve(text1,text2,0,0);
        
        //vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        //return solveMemo(text1,text2,0,0,dp);
        
        return solveTab(text1,text2);
    }
};
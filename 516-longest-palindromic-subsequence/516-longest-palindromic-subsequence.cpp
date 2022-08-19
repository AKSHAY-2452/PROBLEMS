class Solution {
    
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
    int longestPalindromeSubseq(string s) {
        //similar to LCS
        string revStr = s;
        reverse(revStr.begin(),revStr.end());
        return solveTab(s,revStr);
    }
};
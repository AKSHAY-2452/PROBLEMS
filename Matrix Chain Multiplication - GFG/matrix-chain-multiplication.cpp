//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int arr[],int i,int j,vector<vector<int>> &dp){
        if(i == j) return 0;
        if(i > j) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i;k<j;k++){
            int steps = arr[i-1] * arr[k] * arr[j] + solve(arr,i,k,dp) + solve(arr,k+1,j,dp);
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }
    int solveTab(int arr[],int N){
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        
        for(int i = N-1;i>=0;i--){
            for(int j = 0;j<N;j++){
                if(i == j){
                    dp[i][j] = 0;
                    continue;
                }
                else if(i > j){
                    dp[i][j] = 1e9;
                    continue;
                }
                int mini = 1e9;
                for(int k = i;k<j;k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini,steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solveTab(arr,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
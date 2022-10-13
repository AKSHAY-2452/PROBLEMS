class Solution {
    
    int solverec(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(j < i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            int temp = nums[k]*nums[i-1]*nums[j+1];
            int a = temp + solverec(nums,i,k-1,dp) + solverec(nums,k+1,j,dp);
            maxi = max(maxi,a);
        }
        
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        
        
        return solverec(nums,1,n,dp);
    }
};
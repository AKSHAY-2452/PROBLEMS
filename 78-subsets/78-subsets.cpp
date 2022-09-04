class Solution {
    void solve(vector<int>& nums,int ind,vector<int> &temp,vector<vector<int>> &ans){
        //base case
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //include ith element
        temp.push_back(nums[ind]);
        solve(nums,ind+1,temp,ans);
        
        //doesnot include ith element
        temp.pop_back();
        solve(nums,ind+1,temp,ans);
        
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        solve(nums,0,temp,ans);
        
        return ans;
    }
};
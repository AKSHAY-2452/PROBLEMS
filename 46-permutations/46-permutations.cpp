class Solution {
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp,vector<bool> &tempo){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0;j<nums.size();j++){
            if(tempo[j] == false){
                temp.push_back(nums[j]);
                tempo[j] = true;
                solve(nums,ans,temp,tempo);
                tempo[j] = false;
                temp.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> tempo(n,false);
        
        solve(nums,ans,temp,tempo);
        return ans;
    }
};
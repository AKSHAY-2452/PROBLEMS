class Solution {
    int solve(int low,int high,vector<int> &nums){
        if(low>high) return -1;
        int mid = low + (high-low)/2;
        if(mid+1 < nums.size() && nums[mid] > nums[mid+1] && mid-1 >=0 && nums[mid-1]<nums[mid]){
            return mid;
        }
        else if(mid+1 >= nums.size() && mid-1 >=0 && nums[mid-1]<nums[mid]){
            return mid;
        }
        else if(mid-1 < 0 && mid+1 < nums.size() && nums[mid] > nums[mid+1]){
            return mid;
        }
        else{
            int a = solve(mid+1,high,nums);
            if(a != -1) return a;
            a = solve(low,mid-1,nums);
            if(a != -1) return a;
        }
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return solve(0,nums.size()-1,nums);
    }
};
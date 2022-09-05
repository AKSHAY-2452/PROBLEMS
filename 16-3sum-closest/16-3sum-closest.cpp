class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int closest = 1e9;
        if(n<3) return 0;
        for(int i = 0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int currSum = nums[i]+nums[j]+nums[k];
                if(currSum == target) return target;
                if(abs(currSum-target) < abs(closest-target)){
                    closest = currSum;
                }
                
                    if(currSum > target){
                        k--;
                    }
                    else{
                        j++;
                    }
            }
        }
        
        return closest;
    }
};
class Solution {
public:
    int getCombination(vector<int> &nums, int target, vector<int> &dp){
        if(target < 0) return 0;
        else if(target == 0) return 1;
        
        if(dp[target] != -1) return dp[target];
            
        int ans{0};
        for(int i=0;i<nums.size();i++){
            ans += getCombination(nums,target-nums[i],dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target+1,-1);
        return getCombination(nums,target,dp);
    }
};
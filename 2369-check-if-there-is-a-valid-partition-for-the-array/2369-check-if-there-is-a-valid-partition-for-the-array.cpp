class Solution {
public:
    bool validPartition(vector<int>& nums, int idx, vector<int> &dp) {
        if(idx >= nums.size()) return true;
        int length = nums.size() - idx;
        if(length == 1) return 0;
        else if(length == 2) return nums[idx] == nums[idx+1];
        else if(length == 3){
            bool condition2 = nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2];
            bool condition3 = nums[idx] +1 == nums[idx+1] && nums[idx+1] +1 == nums[idx+2];
            if(condition2 || condition3) return true;
            else return false;
        }
        if(dp[idx] != -1) return dp[idx];
            
        bool a{false},b{false};
        bool condition2 = nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2];
        bool condition3 = nums[idx] +1 == nums[idx+1] && nums[idx+1] +1 == nums[idx+2];
        
        if(nums[idx] == nums[idx+1]) a = validPartition(nums,idx+2,dp);
        if(condition2 || condition3) b = validPartition(nums,idx+3,dp);
        return dp[idx] = a||b;
    }
    bool validPartition(vector<int>& nums, int idx = 0) {
        vector<int> dp (nums.size()+1, -1);
        return validPartition(nums,0,dp);
    }
    
};
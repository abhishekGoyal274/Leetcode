class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans{0};
        int min{0}, max{0};
        min = max = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < min) min = nums[i];
            if(nums[i] > max) max = nums[i];
        }
        ans = k * (long long)(max - min);
        return ans;
    }
};
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans{INT_MAX};
        for(int i=0; i<nums.size(); i++){
            int k{0};
            while(nums[i]){
                k += nums[i]%10;
                nums[i] = nums[i]/10;
            }
            ans = min(ans,k);
        }
        return ans;
    }
};
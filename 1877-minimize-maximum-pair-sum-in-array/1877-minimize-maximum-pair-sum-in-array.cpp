class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0;
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        
        int ans{INT_MIN};
        while(i<=n){
            int pair = nums[i]+nums[n];
            ans = max(ans,pair);
            i++,n--;
        }
        return ans;
    }
};
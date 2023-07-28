class Solution {
public:
    int helper(vector<int> &nums,int l, int r){
        if(l>r) return 0;
        int a = nums[l] + min(helper(nums,l+1,r-1),helper(nums,l+2,r));
        int b = nums[r] + min(helper(nums,l+1,r-1),helper(nums,l,r-2));
        return max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int total{0};
        for(auto n:nums) total += n;
        
        int maxScore = helper(nums,l,r);
        return maxScore>=total-maxScore;
    }
};
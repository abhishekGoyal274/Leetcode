class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> left(n,0),right(n,0);
        
        left[0] = nums[0];
        for(int i=1; i<n; i++) left[i] = left[i-1] + nums[i];

        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) right[i] = right[i+1] + nums[i];


        for(int i=0; i<n; i++){
            int l = i-1>=0 ? left[i-1] : 0; 
            int r = i+1<n ? right[i+1] : 0;
            ans[i] = abs(r-l);
        } 

        return ans;
    }
};
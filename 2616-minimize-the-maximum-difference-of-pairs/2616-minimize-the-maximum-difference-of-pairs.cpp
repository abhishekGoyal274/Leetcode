class Solution {
public:
    bool helper(int dif, vector<int> &nums, int p){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] <= dif){
                p--;
                i+=1;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0) return 0;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l{0},r{0};
        for(int i=0; i<n-1; i++){
            int a = nums[i+1] - nums[i];
            r = max(r,a);
        }
        int ans = INT_MAX;
        while(l<=r){
            int m = l + (r-l)/2;
            // cout << m << ", ";
            if(helper(m,nums,p)){
                ans = min(ans,m);
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};
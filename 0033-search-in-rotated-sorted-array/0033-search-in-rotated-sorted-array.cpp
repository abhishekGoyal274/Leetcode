class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            cout << m << ", ";
            if(nums[m] == target) return m;
            if(nums[l] <= nums[m]){
                if(target < nums[m] && nums[l] <= target) {
                    // cout << "right" << endl;
                    r=m-1;
                }
                else{
                    // cout << "left" << endl;
                    l = m+1;
                }
            }else{
                if(target > nums[m] && nums[r] >= target) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};
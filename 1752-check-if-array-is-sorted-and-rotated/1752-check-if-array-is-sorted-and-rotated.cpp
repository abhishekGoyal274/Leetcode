class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated{false}, sorted{false}; 
        int n = nums.size(); int max{INT_MIN};
        for(int i=0; i<n-1; i++){
            if(isRotated == true && nums[i] > nums[0]) return false;
            if(nums[i] <= nums[i+1]) continue;
            
            if(isRotated == false) {
                max = nums[i];
                isRotated = true;
            }
            else return false;
        }
        if(isRotated == true && nums[n-1] > nums[0]) return false;
        return true;
    }
};
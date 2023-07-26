class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int skip = -1;
        for(int i=0; i<nums.size(); i++){
            int num = abs(nums[i]);
            if(num >= nums.size() || (skip != -1 && skip == i)) continue;
            if(nums[num] == 0){
                skip = num;
                nums[0] = -1;
                nums[num] = -1;
            }
            else{
                nums[num] *= -1; 
            }
        }
 
        for(int i=0 ;i < nums.size(); i++){
            if(nums[i] >= 0) return i;
        }
        return nums.size();
    }
};
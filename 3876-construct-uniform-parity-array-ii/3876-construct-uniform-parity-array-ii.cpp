class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool odd{false}, even{false};
        int smallest{INT_MAX};
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0) odd = true;
            else even = true;
            smallest = min(smallest,nums[i]);
        }
        if(!even || !odd) return true;
        else return (smallest)%2 != 0;
    }
};
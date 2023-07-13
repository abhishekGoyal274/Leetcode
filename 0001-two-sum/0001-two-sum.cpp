class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        unordered_map<int,int> pairs;
        for(int i=0; i< nums.size(); i++){
            if(pairs.find(target-nums[i]) != pairs.end() && 2*nums[i]==target){
                v.push_back(i);
                v.push_back(pairs[target-nums[i]]);
                return v;
                
            }
            pairs[nums[i]] = i;
            if(pairs.find(target-nums[i]) != pairs.end() && target-nums[i] != nums[i]
              ){
                v.push_back(i);
                v.push_back(pairs[target-nums[i]]);
                return v;
            }
        }
        return v;
    }
};
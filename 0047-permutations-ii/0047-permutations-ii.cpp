class Solution {
public:
    unordered_map<string,int> um;
     void helper(vector<int> &nums, int idx, vector<int> &perm, vector<vector<int>> &ans){
        if(idx >= nums.size()){
            string s;
            for(int i=0;i <idx; i++){
                s += perm[i] + '-'; 
            }
            if(um.find(s) != um.end()) return;
            um[s]++;
            ans.push_back(perm);
            return;
        }
        
        int num = nums[idx];
        for(int i=0; i<nums.size(); i++){
            if(perm[i] == -20){
                perm[i] = num;
                helper(nums,idx+1,perm,ans);
                perm[i] = -20;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm(nums.size(),-20);
        helper(nums,0,perm,ans);
        return ans;
    }
};
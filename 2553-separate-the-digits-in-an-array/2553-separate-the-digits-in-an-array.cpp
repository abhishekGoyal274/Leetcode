class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(); stack<int> s;
        for(int i=0; i<n; i++){
            int value = nums[i];
            while(value > 0){
                int unit = value%10;
                value = value/10;
                s.push(unit);
            }
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};
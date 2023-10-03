class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans{0};
        unordered_map<int,int> um;
        
        for(auto num:nums) um[num]++;
        for(auto u:um){
            
            int r{2};
            double sum = 1;
            int n = u.second;
            if(n<2) continue;
            
            for(int i = 1; i <= r; i++){
                sum = sum * (n - r + i) / i;
            }
            
            ans += (int)sum;
            
        }
        
        return ans;
    }
};
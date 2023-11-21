class Solution {
public:
    int mod = 1e9 + 7;
    long long rev(int num){
        long long ans{0};
        while(num>0){
            int t = num%10;
            num = num/10;
            ans = ans*10 + t;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,long long> um;
        for(int i=0; i<n; i++){
            long long diff = nums[i] - rev(nums[i]);
            um[diff]++;
        }
        
        long long ans{0};
        for(auto u:um){
            ans += (u.second*(u.second-1))/2; 
            ans %= mod;
        }
        return ans;
    }
};
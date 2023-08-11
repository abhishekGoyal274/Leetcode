class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int N = coins.size();
        vector<long long int>dp(sum+1, 0);
        dp[0] = 1;
        
        for(int i=0; i<N; i++)
            for(long long int j=coins[i]; j<=sum; j++)
                dp[j] += dp[j-coins[i]];
                
        return dp[sum];
    }
};
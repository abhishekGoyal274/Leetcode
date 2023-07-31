class Solution {
public:
    
    int helper(string &s1,string &s2, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1>=s1.length() || idx2>= s2.length()){
            int total{0};
            if(idx1<s1.length()){
                for(int i=idx1; i<s1.length(); i++) total += int(s1[i]);
            }else{
                for(int i=idx2; i<s2.length(); i++) total += int(s2[i]);
            }
            return total;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]) return helper(s1,s2,idx1+1,idx2+1,dp);
        int a = int(s1[idx1]) + helper(s1,s2,idx1+1,idx2,dp);
        int b = int(s2[idx2]) + helper(s1,s2,idx1,idx2+1,dp);
        int c = int(s1[idx1]) + int(s2[idx2]) + helper(s1,s2,idx1+1,idx2+1,dp);
        
        dp[idx1][idx2] = min(a,min(b,c));
        return dp[idx1][idx2];
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int t = max(s1.length(), s2.length());
        vector<vector<int>> dp(t+1, vector<int> (t+1,-1));
        int ans = helper(s1,s2,0,0,dp);
        return ans;
    }
};

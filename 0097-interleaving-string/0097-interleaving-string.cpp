class Solution {
public:
    bool rec(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector<vector<int>> &dp){
        if(n3 == 0){
            if(n1 ==0 && n2==0 && n3==0) return true;
            else return false;
        }
        
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        bool case1{false},case2{false};
        if(n1 != 0 && s1[n1-1] == s3[n3-1]) case1 = rec(s1,s2,s3,n1-1,n2,n3-1,dp);
        if(n2 != 0 && s2[n2-1] == s3[n3-1]) case2 = rec(s1,s2,s3,n1,n2-1,n3-1,dp);
        
        return dp[n1][n2] = case1 || case2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        if(n1 + n2 != n3 ) return false;
        return rec(s1,s2,s3,n1,n2,n3,dp);
    }
};
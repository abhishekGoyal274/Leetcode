class Solution {
public:
    int longestPalin (string &a, string &b, int n1, int n2 ,vector<vector<int>> &dp) {
        if(n1 >= a.length() || n2 >= b.length()) return 0;

        if(dp[n1][n2] == -1){
            if(a[n1] == b[n2]) dp[n1][n2] = 1 + longestPalin (a,b, n1+1,n2+1,dp);
            else{
                int x = longestPalin(a,b,n1+1,n2,dp);
                int y = longestPalin(a,b,n1,n2+1,dp);
                dp[n1][n2] = max(x,y);
            }
        }
        return dp[n1][n2];
    }

    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> dp(a.length(), vector<int>(b.length(),-1));
        return  longestPalin (a,b,0,0,dp);
    }
};
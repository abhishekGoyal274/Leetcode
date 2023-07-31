class Solution {
public:
    int helper(string &word1,string &word2, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1>=word1.length() || idx2>=word2.length()){
            if(idx1<word1.length()) return word1.length()-idx1;
            else return word2.length()-idx2;
        }
        
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(word1[idx1] == word2[idx2])
            return helper(word1,word2,idx1+1,idx2+1,dp);
        
        int insert1,del1;
        insert1 = del1  = 0;
        
        insert1 = helper(word1,word2,idx1,idx2+1,dp);
        del1 = helper(word1,word2,idx1+1,idx2,dp);
        int rep = 0;
        rep = helper(word1,word2,idx1+1,idx2+1,dp);
        
        int a = del1;
        int b = insert1;
        int c = rep;
        
        dp[idx1][idx2] =  1 + min(a, min(b,c));
        return dp[idx1][idx2];
    }
    int minDistance(string word1, string word2) {
        int t = max(word1.length(), word2.length());
        vector<vector<int>> dp(t+1, vector<int> (t+1,-1));
        int ans = helper(word1,word2,0,0,dp);
        return ans;
    }
};
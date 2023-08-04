class Solution {
public:
    bool ans{false};
    bool helper(string &s, int start, unordered_map<string,int> &um, vector<int> &dp){
        if(start >= s.length()) return true;
        
        if(dp[start] != -1) return dp[start];
        
        bool found{false};
        for(int i = 0; start+i<=s.length() ;i ++){
            string sub = s.substr(start,i);
            if(um.find(sub) != um.end()) {
                found = found || helper(s,start+i,um,dp);
            }
        }
        dp[start] = found;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> v(26,0);
        unordered_map<string,int> um;
        vector<int> dp(s.length(),-1);
        for(auto word:wordDict) {
            um[word]++;
            for(int i=0; i<word.length(); i++) v[word[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++){
            int idx = s[i] - 'a';
            if(v[idx] == 0) return false;
        }
        return helper(s,0,um,dp);
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t, int idx1=0, int idx2=0) {
        if(idx1 >= s.length()) return true;
        else if(idx2 > t.length()) return false;
        
        if(s[idx1] == t[idx2]) return isSubsequence(s,t,idx1+1,idx2+1);
        else return isSubsequence(s,t,idx1,idx2+1);
    }
};
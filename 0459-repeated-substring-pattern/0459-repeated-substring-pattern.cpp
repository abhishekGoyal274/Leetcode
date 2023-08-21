class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        bool possible{false};
        for(int i=n/2; i>0; i--){
            if(n%i != 0) continue;
            string subStr = s.substr(0,i);
            
            int idx = i;
            while(idx < n){
                string t = s.substr(idx,i);
                if(t == subStr) idx += i;
                else break;
            }
            if(idx==n){
                possible = true;
                break;
            }
        }
        return possible;
    }
};
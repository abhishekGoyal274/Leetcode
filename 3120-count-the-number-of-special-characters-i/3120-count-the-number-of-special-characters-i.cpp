class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans{0};
        vector<int> lower(26-0), upper(26,0);
        for(auto w:word){
            if(islower(w)) lower[w - 'a']++;
            else upper[w - 'A']++; 
        }
        for(int i=0; i<26; i++) ans += lower[i] && upper[i];
        return ans;
    }
};
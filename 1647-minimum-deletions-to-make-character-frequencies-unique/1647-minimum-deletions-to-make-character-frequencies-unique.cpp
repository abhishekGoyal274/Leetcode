class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        
        for(auto ch: s) freq[ch-'a']++;
        sort(freq.begin(), freq.end());
            
        int ans{0};
        for(int i=0; i<25; i++){
            if(freq[i] != freq[i+1] || freq[i] == 0) continue;
            
            int newVal{0};
            for(int j=i; j>=0; j--){
                if(j==0) {
                    if(freq[0] != 0) newVal = freq[0] -1;
                    break;
                }
                else if(freq[j] - freq[j-1] > 1){
                    newVal = freq[j]-1;
                    break;
                }
            }
            ans += freq[i] - newVal;
            freq[i] = newVal;
            sort(freq.begin(), freq.end());
            
        }
        return ans;
    }
}; 
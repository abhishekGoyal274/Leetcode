class Solution {
public:
    int setBit(int i){
        int count{0};
        while(i>0){
            if(i & 1) count++;
            i/=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n; i++){
            ans[i] = setBit(i);
        }
        return ans;        
    }
};
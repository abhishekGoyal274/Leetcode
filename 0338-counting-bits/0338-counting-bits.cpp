class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n == 0) return ans;
        else if(n == 1){
            ans[1] = 1;
            return ans;
        }else if(n == 2){
            ans[1] = 1;
            ans[2] = 1;
            return ans;
        }
        ans[1] = ans[2] = 1;
        int powerOftwo{2};
        for(int i=3; i<=n; i++){
            if((i&(i-1)) == 0){
                ans[i] = 1;
                powerOftwo = i;
            }
            else ans[i] = ans[powerOftwo] + ans[i-powerOftwo];
        }
        return ans;        
    }
};
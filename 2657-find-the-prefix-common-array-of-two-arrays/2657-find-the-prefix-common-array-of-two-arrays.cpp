class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), total = n; 
        vector<int> ans(n,0), freqA(n,0), freqB(n,0); 
        for(int i=n-1; i>=0; i--){
            ans[i] = total;
            if(A[i] == B[i]) total -= 1;
            else{
                if(freqA[B[i]-1] == 0){
                    total--;
                    freqB[B[i]-1] = 1;
                }
                if(freqB[A[i]-1] == 0){
                    total--;
                    freqA[A[i]-1] = 1;
                }
            }
        }
        return ans;
    }
};
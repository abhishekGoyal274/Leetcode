class Solution {
public:
    int solve(int val, int level, int n, int k){
        if(level == n) return val;
    
        int depth = (n-level);
        int nodes = pow(2,depth);
        
        // cout << val << "  " << level << " " << n << " " << k << " : " << depth << " " << nodes << endl;    
        
        if(k<=nodes/2) {
            if(val == 0) return solve(0,level+1,n,k);
            else return solve(1,level+1,n,k);
        }
        else {
            if(val == 0) return solve(1,level+1,n,k-(nodes/2));
            else return solve(0,level+1,n,k-(nodes/2));
        }
    }
    int kthGrammar(int n, int k) {
        int ans = solve(0,1,n,k);
        return ans;
    }
};
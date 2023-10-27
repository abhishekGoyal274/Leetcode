//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &s, int left, int right, vector<vector<int>> &dp){
        if(left>= right) return 0;
        
        if(dp[left][right] != -1) return  dp[left][right];
        
        if(s[left] == s[right]) return dp[left][right] = solve(s,left+1,right-1,dp);
        else return dp[left][right] = 1 + min(solve(s,left,right-1,dp) ,solve(s,left+1,right,dp) );
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = solve(S,0,S.length()-1,dp);
        return ans;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
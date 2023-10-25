//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[], vector<vector<int>> &dp){
        // code here
        if(W == 0 || N == 0) return 0;
        
        if(dp[N][W] != -1) return dp[N][W]; 
        
        int a{0},b{0};
        if(wt[N-1] <= W) a = val[N-1] + knapSack(N,W-wt[N-1],val,wt,dp);
        b = knapSack(N-1,W,val,wt,dp);
        
        return dp[N][W] = max(a,b);
    }
    
    int knapSack(int N, int W, int val[], int wt[]){
        vector<vector<int>> dp(N+1, vector<int> (W+1,-1));
        return knapSack(N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
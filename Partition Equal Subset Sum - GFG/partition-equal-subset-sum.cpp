//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int idx, int n, int sum, int total, vector<vector<int>> &dp){
        if(total == sum/2) return 1;
        if(idx >= n) return 0;
        
        if(dp[idx][total] != -1) return dp[idx][total];
        int a = solve(arr,idx+1,n,sum,total+arr[idx],dp);
        int b = solve(arr,idx+1,n,sum,total,dp);
        
        if(a==1 || b==1) return dp[idx][total] = 1;
        else return dp[idx][total] = 0;
    }
    
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum{0};
        for(int i=0; i<n; i++) sum += arr[i];
        if(sum%2 != 0) return 0;
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return solve(arr,0,n,sum,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
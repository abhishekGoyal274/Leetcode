//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
    {
        // your code here
        if(m>=s1.length() || n>=s2.length()) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m] == s2[n]){
            dp[m][n] = 1 + lcs(s1,s2,m+1,n+1,dp);
            return dp[m][n];
        }
        int a = lcs(s1,s2,m,n+1,dp);
        int b = lcs(s1,s2,m+1,n,dp);
        dp[m][n] = max(a,b);
        
        return dp[m][n];
    }
    int lcs(int m, int n, string &s1, string &s2)
    {
        // your code here
        vector<vector<int>> dp(m+1,vector<int>(n+1, -1));
        return lcs(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
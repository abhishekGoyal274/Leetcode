//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1000000007;
    long long countWays(int n)
    {
        // your code here
        if(n <=3){
            if(n==1) return 1;
            if(n==2) return 2;
            if(n==3) return 4;
        }
        
        vector<long long> dp(n+1,-1);
        dp[n] = 0;
        dp[n-1] = 1;
        dp[n-2] = 2;
        dp[n-3] = 4;
        for(int i=n-4; i>=0; i--){
            dp[i] = (dp[i+1] + dp[i+2] + dp[i+3] )%mod;
        }
        
        return dp[0];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
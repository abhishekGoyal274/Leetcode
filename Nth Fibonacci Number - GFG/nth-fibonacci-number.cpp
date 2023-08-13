//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1000000007;
    int nthFibonacci(int n){
        // code here
        if(n<=2) return 1;
        int a{1},b{1},ans{0};
        for(int i=3; i<=n;i++){
            ans = a+b;
            a = b;
            b = ans;
            a %= mod;
            b %= mod;
            ans %= mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
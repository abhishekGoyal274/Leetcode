//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long ans{0};
        while(N%2==0){
            N/=2;
            ans = 2;
        }
        for(int i=3; i*i <= N; i+=2){
            while(N%i==0){
                N/=i;
                ans = i;
            }
        }
    
        if(N > ans) return N;
        else return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
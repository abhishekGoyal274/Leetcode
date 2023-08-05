//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        if(m==1) return 0;
        sort(a.begin(),a.end());
        
        long long diff{INT_MAX};
        for(int i=0; i+m-1<a.size(); i++){
            diff = min(diff, a[m+i-1]- a[i]);
            // cout << diff << " " << a[i] << " " << a[m+i-1] << endl;
        }
        return diff;
    }   
};                                                                                                                  

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
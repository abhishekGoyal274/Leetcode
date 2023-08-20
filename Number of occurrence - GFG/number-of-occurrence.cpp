//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	void binarySearch(int &mmax, int &mmin, int l, int r, int arr[], int &x){
	    if(l>r) return;
	    
	    int m = l + (r-l)/2;
	    if(arr[m] == x){
	        mmin = min(mmin,m);
	        mmax = max(mmax,m);
	        binarySearch(mmax,mmin,l,m-1,arr,x);
	        binarySearch(mmax,mmin,m+1,r,arr,x);
	    }
	    else if(arr[m] > x) binarySearch(mmax,mmin,l,m-1,arr,x);
	    else binarySearch(mmax,mmin,m+1,r,arr,x);
	}
	int count(int arr[], int n, int x) {
	    // code here
	    if(n==1) return arr[0] == x;
	    int mmin{n-1},mmax{0};
	    binarySearch(mmax,mmin,0,n-1,arr,x);
	    if(mmax == 0 && mmin == n-1) return 0;
	    else return mmax-mmin+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
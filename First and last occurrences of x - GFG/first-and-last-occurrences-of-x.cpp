//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans(2,-1);
        
        int l{0},r{n-1};
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr[m] >= x){
                if(arr[m] == x) ans[0] = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        
        l = 0,r = n-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr[m] <= x){
                if(arr[m] == x) ans[1] = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        
        return  ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
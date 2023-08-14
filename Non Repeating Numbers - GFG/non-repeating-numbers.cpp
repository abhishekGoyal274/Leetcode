//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size();
        int x = nums[0];
        for(int i=1; i<n; i++){
            x ^= nums[i];
        }
        
        int setBit = (x) & ~(x-1);
        int a{0},b{0};
        for(int i=0; i<n;i++){
            
            if((setBit&nums[i]) == setBit){
                // cout << "a: " << nums[i] << endl;
                a ^= nums[i];
            }else{
                // cout << "b: " << nums[i] << endl;
                b ^= nums[i];
            }
        }
        // cout << x << " " << setBit << endl;
        // cout << a << " " << b << endl;
        int smaller = a<b?a:b;
        int larger = a+b-smaller;
        
        return {smaller,larger};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    pair<int,int> emptyPair = {0,0};
		    vector<pair<int,int>> storage(26,emptyPair);
		    for(int i=0; i<A.length(); i++){
		        int n = A[i]-'a';
		        pair<int,int> p = storage[n];
		        if(p.second == 0){
		            storage[n] = {i,1};
		        }else{
		            storage[n] = {p.first,p.second+1};
		        }
		        
		        int t = INT_MAX;
		        int  num = -1;
		        for(int i=0; i<26; i++){
		            pair<int,int> p = storage[i];
		            if(p.second == 1 && p.first<t){
		                t = p.first;
		                num = i;
		            }
		        }
		        if(num == -1) cout << "#";
		        else{
		            char c = 'a' + num;
		            cout << c;
		        }
		    }
		    string ans;
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
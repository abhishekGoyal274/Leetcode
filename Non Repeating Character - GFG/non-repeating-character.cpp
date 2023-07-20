//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       vector<pair<int,int>> storage(26, {-1,0}); 
       char m = '$';
       int t = INT_MAX;
       for(int i=0; i<S.length(); i++){
           int val = S[i] - 'a';
           pair<int,int> p = storage[val];https://www.geeksforgeeks.org/geek-olympics-2023
           int freq = p.second;
           if(p.first == -1) storage[val] = {i,1};
           else storage[val] = {p.first, freq+1};
       }
      for(int i=0; i<26; i++){
          pair<int,int> p = storage[i];
          if(p.second == 1 && p.first < t){
              t = p.first;
              m = 'a' + i;
          }
      }
       return m;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
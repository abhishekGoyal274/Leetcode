//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void helper(vector<string> &ans, int idx, string &sub, string &s){
        if(idx >= s.length()){
            ans.push_back(sub);
        }
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != '1'){
                char temp = s[i];
                sub.push_back(s[i]);
                s[i] = '1';
                helper(ans,idx+1,sub,s);
                sub.pop_back();
                s[i] = temp;
            }
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        sort(s.begin(), s.end());
        vector<string> ans;
        string sub;
        helper(ans,0,sub,s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        vector<vector<int>> mat (n, vector<int> (n,INT_MAX));
        for(int i=0; i<n; i++) mat[i][i] = 0;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            mat[u][v] = d;
            if(u == 0) ans[v] = d;
        }
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            int m{INT_MAX};
            for(int i=0;i <n; i++){
                if(ans[i] != INT_MAX && !visited[i]){
                    if(m == INT_MAX || ans[m] > ans[i]) m = i;  
                }
            }
            if(m == INT_MAX){
                for(auto &a:ans) {
                    if(a == INT_MAX) a = -1; 
                }
                return ans;
            }
            visited[m] = true;
            for(int i=0; i<n; i++){
                int dis = mat[m][i];
                if(dis == INT_MAX) continue;
                if(ans[i] > ans[m] + dis) ans[i] = ans[m] + dis;
            }
        }
        for(auto &a:ans) {
            if(a == INT_MAX) a = -1; 
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
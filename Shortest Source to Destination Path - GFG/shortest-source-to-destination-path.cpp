//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> arr, int x, int y) {
        // code here
        queue<pair<int,int>> q;
        if(arr[0][0] == 0) return -1;
        q.push({0,0});
        arr[0][0] = 1;
        int ans{0};
        while(!q.empty()){
            int count = q.size();
            while(count--){
                pair<int,int> front = q.front();
                q.pop();
                int a = front.first;
                int b = front.second;
                if(a == x && b ==y) return ans;
                vector<int> xAxis = {0,0,1,-1};
                vector<int> yAxis = {1,-1,0,0};
                for(int i=0; i<4; i++){
                  int x1 = a + xAxis[i];  
                  int y1 = b + yAxis[i];  
                  if(x1>=0 && y1>=0 && x1<n && y1<m && arr[x1][y1] == 1){
                      arr[x1][y1] = 0;
                      q.push({x1,y1});
                  }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
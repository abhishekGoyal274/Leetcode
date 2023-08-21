//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool checkSurroundings(vector<vector<int>> &matrix, int &i, int &j, int &m, int &n){
        vector<int> x = {1,1,1,-1,-1,-1,0,0};
        vector<int> y = {0,-1,1,-1,1,0,1,-1};
        int count{0};
        for(int k=0; k<8; k++){
            int xCoord = i+x[k]; 
            int yCoord = j+y[k];
            if(xCoord >=0 && xCoord<m && yCoord>=0 && yCoord<n && matrix[xCoord][yCoord] == 0) count++;
        }
        return count != 0 && count%2==0;
    }
    int Count(vector<vector<int>> &matrix) {
        // Code here
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans{0};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) continue;
                if(checkSurroundings(matrix,i,j,m,n)) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
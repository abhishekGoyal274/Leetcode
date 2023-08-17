class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q; 
            
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) mat[i][j] = INT_MAX;
                else q.push({i,j});
            }
        }
        
        int dis{0};
        vector<int> a = {1,-1,0,0};
        vector<int> b = {0,0,1,-1};
        while(!q.empty()){
            int count = q.size();
            while(count--){
                pair<int,int> coords = q.front();
                q.pop();
                
                int i = coords.first;
                int j = coords.second;
                
                mat[i][j] = min(mat[i][j],dis);
                for(int k=0; k<4;k++){
                    int x = i + a[k];
                    int y = j + b[k];
                    if(x>=0 && y>=0 && x<m && y<n && mat[x][y] == INT_MAX){
                        q.push({x,y});
                    }
                }
            }
            dis++;
        }
        return mat;
    }
};
class Solution {
public:
    int  helper(int x, int y, vector<vector<int>> &grid,int &m, int &n, vector<vector<int>> &dp){
        if(x<0 || y<0 || x >=m || y>=n || grid[x][y] == 1) return 0;
        if (x == m-1 && y==n-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = helper(x+1,y,grid,m,n,dp) + helper(x,y+1,grid,m,n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m,vector<int>(n,-1));
        return helper(0,0,grid,m,n,dp);
    }
};
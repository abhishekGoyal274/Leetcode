class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> matrix(query_row+2, vector<double> (query_row+2,0));
        unordered_map<string,int> um;
        queue<pair<int,int>> q;
        matrix[0][0] = poured;
        q.push({0,0});
        int x{0};
        while(!q.empty()){
            if(x > query_row) break;
            int count  =  q.size();
            while(count--){
                auto coords = q.front();
                q.pop();
                
                int i = coords.first;
                int j = coords.second;
                
                double liquid = matrix[i][j];
                if(liquid <= 1) continue;
                
                int left = j;
                int right = j+1;
                
                double split = (liquid-1);
                matrix[i][j] -= split;
                
                matrix[i+1][left] += split/2;
                matrix[i+1][right] += split/2;
                
                if(matrix[i+1][left] > 1) q.push({i+1,left});
                if(matrix[i+1][right] > 1) q.push({i+1,right});
                
            }
            x++;
        }
        return matrix[query_row][query_glass];
    }
};
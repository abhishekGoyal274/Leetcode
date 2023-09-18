class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        map<int,vector<int>> m;
        for(int i=0; i< mat.size(); i++){
            int count{0};
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0) break;
                count++;
            }
            m[count].push_back(i);
        }
        
        auto it = m.begin();
        while(ans.size() < k){
            vector<int> rows = it->second;
            for(int i=0; i<rows.size(); i++){
                if(ans.size() == k) return ans;
                ans.push_back(rows[i]);
            }
            it++;
        }
        return ans;
    }
};
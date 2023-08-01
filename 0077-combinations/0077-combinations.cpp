class Solution {
public:
    void helper(vector<vector<int>> &ans, int &k, int number, int &n, vector<int> &comb){
        if(comb.size() == k ) {
            ans.push_back(comb);
            return;
        }
        if(comb.size() > k || number > n) return;
        
        helper(ans, k, number+1, n, comb);
        comb.push_back(number);
        helper(ans, k, number+1, n, comb);
        comb.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(ans, k, 1, n, comb);
        return ans;
    }
};
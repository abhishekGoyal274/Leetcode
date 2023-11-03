class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string PUSH = "Push";
        string POP = "Pop";
        int j{0},i{1};
        while(i<=n && j < target.size()){
            if(i == target[j]) {
                ans.push_back(PUSH);
                j++;
            }
            else{
                ans.push_back(PUSH);
                ans.push_back(POP);
            }
            i++;
        }
        return ans;
    }
};
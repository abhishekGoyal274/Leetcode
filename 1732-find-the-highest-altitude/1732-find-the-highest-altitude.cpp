class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int gains{0}, ans{0};
        for(const auto &g:gain){
            gains += g;
            ans = max(ans, gains);
        }
        return ans;
    }
};
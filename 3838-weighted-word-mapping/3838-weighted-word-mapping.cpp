class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans{};
        for(auto word: words){
            int totalWeight{0};
            for(auto character: word){
                int index = character - 'a';
                totalWeight += weights[index];
            }
            totalWeight %= 26;
            char c = 'z' - totalWeight;
            ans.push_back(c);
        }
        return ans;
    }
};
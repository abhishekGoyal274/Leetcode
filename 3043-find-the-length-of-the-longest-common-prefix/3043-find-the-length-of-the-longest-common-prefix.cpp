// Trie Node Class

class Trie{
    private:
        vector<Trie*> children;
    public:
        Trie() : children(10, nullptr) {}
        void insert(string &word, int index){
            if(index >= word.length()) {
                return;
            }
            int id = word[index] - '0';
            if(this->children[id] == nullptr) this->children[id] = new Trie();
            this->children[id]->insert(word,index+1);
        }
        int findPrefixLength(string &word, int index){
            int id = word[index] - '0';
            if(index >= word.length() || this->children[id] == nullptr) return 0;
            return 1 + this->children[id]->findPrefixLength(word, index+1);
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(); int m = arr2.size();
        int ans{0};
        Trie *T = new Trie();
        for(int j=0; j<m; j++){
            std::string word = std::to_string(arr2[j]);
            T->insert(word, 0);
        }
        for(int i=0; i<n; i++){
            std::string word = std::to_string(arr1[i]);
            ans = max(ans, T->findPrefixLength(word, 0));
        }
        return ans;
    }
}; 
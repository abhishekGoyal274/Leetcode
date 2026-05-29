#include <vector>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        
        // Track the overall global fallback (shortest word, lowest index)
        int rootMinLen = INT_MAX;
        int rootIndex = INT_MAX;
        
        // Maps a suffix hash -> index of the best word in wordsContainer
        unordered_map<size_t, int> suffixMap;
        
        // Custom string hasher to create unique keys for suffixes
        hash<string_view> SVHasher;

        for (int i = 0; i < n; i++) {
            const string& word = wordsContainer[i];
            int len = word.length();
            
            // Update global fallback
            if (len < rootMinLen) {
                rootMinLen = len;
                rootIndex = i;
            }
            
            // Generate all suffixes of this word from right to left
            // Using string_view avoids duplicating/copying the string data!
            string_view sv(word);
            for (int j = len - 1; j >= 0; j--) {
                string_view suffix = sv.substr(j);
                size_t h = SVHasher(suffix);
                
                if (suffixMap.find(h) == suffixMap.end()) {
                    suffixMap[h] = i;
                } else {
                    int existingIdx = suffixMap[h];
                    // Tie-breaking: shorter length first, then smaller index
                    if (len < wordsContainer[existingIdx].length()) {
                        suffixMap[h] = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(m);
        
        for (int i = 0; i < m; i++) {
            const string& query = wordsQuery[i];
            int len = query.length();
            string_view sv(query);
            
            int bestIndex = rootIndex; // Fallback default
            
            // Search from longest possible suffix down to single char suffix
            for (int j = 0; j < len; j++) {
                string_view suffix = sv.substr(j);
                size_t h = SVHasher(suffix);
                
                if (suffixMap.find(h) != suffixMap.end()) {
                    bestIndex = suffixMap[h];
                    break; // Found the longest matching suffix, we can stop!
                }
            }
            ans.push_back(bestIndex);
        }
        
        return ans;
    }
};
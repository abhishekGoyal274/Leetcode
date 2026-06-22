class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = -1;
        const string BALLOON = "balon";
        std::unordered_map<char, int> frequency;
        for(auto character:BALLOON) frequency[character] = 0;
        for(int i=0; i<text.length(); i++){
            if(BALLOON.contains(text[i])){
                frequency[text[i]]++;
            }
        }
        for(auto f:frequency){
            cout << f.first  << " " << f.second << endl;
            if(ans == -1){
                if(f.first == 'l' || f.first == 'o') ans = f.second/2;
                else ans = f.second;
            }else{
                if(f.first == 'l' || f.first == 'o') ans = std::min(ans, f.second/2);
                else ans = std::min(ans, f.second);
            }
        }
        return ans;
    }
};
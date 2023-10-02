class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        if(n <= 2) return false;
        
        int alice{0}, bob{0};
    
        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A'){
                if(colors[i-1] == 'A' && colors[i+1] == 'A') alice++;
            }else{
                if(colors[i-1] == 'B' && colors[i+1] == 'B') bob++;
            }
        }
        
        if(alice >= bob+1) return true;
        return false;
    }
};
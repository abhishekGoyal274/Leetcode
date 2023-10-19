class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
              
        stack<char> s1,s2;
        for(auto ch: s){
            if(ch != '#'){
                s1.push(ch);
                continue;
            }
            if(!s1.empty()) s1.pop();
        }
        
        for(auto ch: t){
            if(ch != '#'){
                s2.push(ch);
                continue;
            }
            if(!s2.empty()) s2.pop();
        }
        
        while(!s1.empty() && !s2.empty()){
            char t1 = s1.top();
            s1.pop();
            
            char t2 = s2.top();
            s2.pop();
            
            if(t1 != t2) return false;
        }
        
        if(!s1.empty() || !s2.empty()) return false;
        else return true;
        
    }
};
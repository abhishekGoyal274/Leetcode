class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        for(int i =0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                s.push(asteroids[i]);
            }
            else if (asteroids[i] == 0) {}
            else{
                int neg = abs(asteroids[i]);
                bool destroyed = false;
                while(!s.empty() && s.top() <= neg){
                    if(s.top() == neg){
                        s.pop();
                        destroyed = true;
                        break;
                    }
                    s.pop();
                }
                if(s.empty() && !destroyed) ans.push_back(neg*(-1));
            }
        }
        for(auto a:ans) cout << a << " ";
        stack<int>p;
        while(!s.empty()){
            p.push(s.top());
            s.pop();
        }
        while(!p.empty()){
            ans.push_back(p.top());
            cout << p.top() << " ";
            p.pop();
        }
        return ans;
    }
};
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool ans{true};
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(auto asteroid: asteroids){
            if(m >= asteroid) m += asteroid;
            else if(m >= 1'00'000) return true;
            else return false;
        }
        return ans;
    }
};
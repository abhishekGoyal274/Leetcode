class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool ans{true};
        sort(asteroids.begin(), asteroids.end());
        for(auto asteroid: asteroids){
            if(mass >= asteroid) {
                int sub = INT_MAX - mass;
                if(asteroid >= sub) return true;
                mass += asteroid;
            }
            else return false;
        }
        return ans;
    }
};
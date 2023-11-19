class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> m;
        int ans{0};
        for(auto num: nums) m[num]++;
        
        auto back = m.end();
        back--;
        
        int temp = 0;
        while(back != m.begin()){
            
            int key = back->first;
            int val = back->second;
            temp = temp + val;
            ans += temp;
            back--;
        }
        
        return ans;
    }
};
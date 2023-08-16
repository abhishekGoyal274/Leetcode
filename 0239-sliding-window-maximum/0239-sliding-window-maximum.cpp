class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        
        for(int i=0; i<k; i++){
            m[nums[i]]++;
        }
        
        auto e = m.end();
        e--;
        ans.push_back(e->first);
        
        for(int i=k; i<nums.size(); i++){
            int prev = nums[i-k];
            int next = nums[i];
            if(m[prev] > 1) m[prev]--;
            else m.erase(prev);
            m[next]++;
            
            auto e = m.end();
            e--;
            ans.push_back(e->first);
        }
        return ans;
    }
};
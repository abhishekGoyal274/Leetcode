class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> um;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int group = groupSizes[i];
            um[group].push_back(i);
        }
        for(auto group: um){
            int groupSize = group.first;
            vector<int> members = group.second;
            for(int i=0; i<members.size(); i+=groupSize){
                vector<int> group;
                for(int j=0; j<groupSize; j++){
                    group.push_back(members[i+j]);
                }
                ans.push_back(group);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        
        vector<pair<int,int>> vec;
        vector<int> candies(n,1);
        int ans = n;
        
        for(int i=0; i<n; i++) vec.push_back({ratings[i],i});
        sort(vec.begin(), vec.end());
        
        for(int j=0; j<n; j++){
            
            int i = vec[j].second;
                
            if(i == 0){
                if(ratings[i] > ratings[i+1] && candies[i+1] >= candies[i]){
                    ans+= abs(candies[i+1] - candies[i]) + 1;
                    candies[i] = candies[i+1] + 1;
                
                }
            }
            else if(i == n-1){
                if(ratings[i] > ratings[i-1] && candies[i-1] >= candies[i]){
                    ans+= abs(candies[i-1] - candies[i]) + 1;
                    candies[i] = candies[i-1] + 1;

                }
                
            }
            else{
                int candy{0};
                if(ratings[i] > ratings[i+1] && candies[i+1] >= candies[i]){
                    candy = max(candy, abs(candies[i+1] - candies[i]) + 1 );
                }
                if(ratings[i] > ratings[i-1] && candies[i-1] >= candies[i]){
                    candy = max(candy, abs(candies[i-1] - candies[i]) + 1 );
                }
                ans += candy;
                candies[i] = candies[i] + candy;
                cout << ans << endl;
            }
        }
            
        return ans;
    }
};
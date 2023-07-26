class Solution {
public:
    bool check(vector<int> &dist, int m, double hour){
        double total{0};
        for(int i=0; i<dist.size(); i++){
            double tmp = dist[i];
            if(i == dist.size()-1) total += tmp/m;
            else total += ceil(tmp/m);
        }
        cout << total << " ";
        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size() >  ceil(hour)) return -1;
        int l{1},r{10000000};
        int ans{INT_MAX};
        while(l<=r){
            int m = l + (r-l)/2;
            if(check(dist,m,hour)){
                ans = min(ans,m);
                r = m-1;
            }else{
                l = m+1;
            }
            cout << m << endl;
        }
        return ans;
    }
};
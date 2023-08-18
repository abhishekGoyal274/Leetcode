class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int> (n,0));
        vector<int> childs (n,0);
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            
            childs[u]++;
            childs[v]++;
        }
        
        int m{0};
        for(int i=0; i<n; i++){
            int t = childs[i], k{0};
            for(int j=i+1; j<n; j++){
                if(adj[i][j] == 1) k = max(k,childs[j]-1);
                else k = max(k,childs[j]);
            }
            m = max(m,t+k);
        }
        return m;
    }
};
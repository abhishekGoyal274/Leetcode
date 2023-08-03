class Solution {
public:
    vector<vector<int>> ans;
    int helper(vector<vector<int>> &adj,int parent, vector<int> &des, vector<int> &low, int node, int &tym){
        if(des[node] != INT_MAX) return des[node];
        des[node] = tym;
        int l = tym;
        for(auto child: adj[node]){
            if(child == parent) continue;
            int t;
            if(des[child] != INT_MAX){
                t = des[child];
            }
            else{
                t = helper(adj,node,des,low,child, ++tym);
                if(low[child] > des[node]) ans.push_back({node,child});
            }
            l = min(l,t);
        }
        low[node] = l;
        return low[node];
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto conn: connections){
            int u = conn[0];
            int v = conn[1];  
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> des(n,INT_MAX);
        vector<int> low(n,INT_MAX); 
        low[0] = 0;
        int tym{0};
        helper(adj,-1,des,low,0,tym);
        for(int i=0; i<n; i++){
            cout << "node: " << i << " des: " << des[i] << " low: " << low[i] << endl;
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(int x : adj[node]) {
            if(!vis[x])
                dfs(x, adj, vis);
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        if(edges.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count - 1;
    }
};
class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(V, 0);
        vector<int> cnt(V, 0);
        vector<bool> inQueue(V, true);

        queue<int> q;

        for(int i = 0; i < V; i++) {
            q.push(i);
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for(auto it : adj[u]) {

                int v = it.first;
                int wt = it.second;

                if(dist[u] + wt < dist[v]) {

                    dist[v] = dist[u] + wt;
                    cnt[v]++;

                    if(cnt[v] >= V)
                        return true;

                    if(!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        return false;
    }
};
class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        if (u == v) return true;

        int V = adj.size();
        vector<bool> visited(V, false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (neighbor == v) return true;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

class Solution {
private:
    vector<int> parent;
    vector<int> sz;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Returns the number of new paths formed by union
    long long unionSets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            long long newPaths = (long long)sz[root_i] * sz[root_j];

            // Union by size
            if (sz[root_i] < sz[root_j]) {
                swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];

            return newPaths;
        }
        return 0;
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        int q = queries.size();
        vector<int> ans(q, 0);

        // Pair structure: {query_value, original_index}
        vector<pair<int, int>> sortedQueries(q);
        for(int i = 0; i < q; i++) {
            sortedQueries[i] = {queries[i], i};
        }

        // Sort queries and edges in ascending order of their weights
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // Initialize DSU structures
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        long long currentPaths = 0;
        int edgeIdx = 0;
        int numEdges = edges.size();

        // Process each query
        for(int i = 0; i < q; i++) {
            int maxWeightAllowed = sortedQueries[i].first;
            int originalIdx = sortedQueries[i].second;

            // Add all edges that have weight less than or equal to the allowed max
            while(edgeIdx < numEdges && edges[edgeIdx][2] <= maxWeightAllowed) {
                int u = edges[edgeIdx][0];
                int v = edges[edgeIdx][1];
                currentPaths += unionSets(u, v);
                edgeIdx++;
            }

            ans[originalIdx] = currentPaths;
        }

        return ans;
    }
};

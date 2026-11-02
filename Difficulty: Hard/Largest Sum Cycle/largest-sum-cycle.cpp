class Solution {
  public:
    int largestSumCycle(vector<int>& edge) {
        int n = edge.size();
        int maxCycleSum = -1;

        // 0 = unvisited, 1 = visiting (current path), 2 = completely processed
        vector<int> visited(n, 0); 
        vector<int> path; 

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                int curr = i;
                path.clear();

                // Traverse until we hit an empty edge or a node processed in a previous path
                while (curr != -1 && visited[curr] != 2) {
                    if (visited[curr] == 1) {
                        // Cycle detected! Find where the cycle starts in our path history
                        int currentCycleSum = 0;
                        auto it = find(path.begin(), path.end(), curr);

                        // Sum up all node indices from the start of the cycle to the end of the path
                        while (it != path.end()) {
                            currentCycleSum += *it;
                            it++;
                        }

                        maxCycleSum = max(maxCycleSum, currentCycleSum);
                        break;
                    }

                    // Mark as visiting in the current path
                    visited[curr] = 1;
                    path.push_back(curr);
                    curr = edge[curr];
                }

                // Mark all nodes traversed in this path as completely processed
                for (int node : path) {
                    visited[node] = 2;
                }
            }
        }

        return maxCycleSum;
    }
};

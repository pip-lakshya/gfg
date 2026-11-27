class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        int totalDegree = 0;
        for (const auto& neighbors : adj) {
            totalDegree += neighbors.size();
        }
        return totalDegree / 2;
    }
};

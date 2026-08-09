class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp(n);

        // First row: we can start from any column
        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++) {
            vector<int> ndp(n, 0);

            for (int j = 0; j < n; j++) {

                int best = 0;

                // Previous row: choose a DIFFERENT column
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        best = max(best, dp[k]);
                    }
                }

                ndp[j] = mat[i][j] + best;
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Day 0
        dp[0][0] = 0;       // No task
        dp[0][1] = l[0];   // Low effort
        dp[0][2] = h[0];   // High effort

        for (int i = 1; i < n; i++) {

            // Do nothing today
            dp[i][0] = max({
                dp[i-1][0],
                dp[i-1][1],
                dp[i-1][2]
            });

            // Low effort today
            dp[i][1] = max({
                dp[i-1][0],
                dp[i-1][1],
                dp[i-1][2]
            }) + l[i];

            // High effort today
            // Previous day MUST be nothing
            dp[i][2] = dp[i-1][0] + h[i];
        }

        return max({
            dp[n-1][0],
            dp[n-1][1],
            dp[n-1][2]
        });
    }
};
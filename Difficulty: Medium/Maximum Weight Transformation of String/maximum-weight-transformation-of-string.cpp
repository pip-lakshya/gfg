class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;

            if (i >= 2) {
                int cost = (s[i - 2] == s[i - 1]) ? 1 : 0;
                dp[i] = max(dp[i], dp[i - 2] + 4 - cost);
            }
        }

        return dp[n];
    }
};
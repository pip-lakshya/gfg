class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        vector<int> dp(1000002, 0);

        int ans = 1;

        for (int x : arr) {
            dp[x] = max(dp[x], max(dp[x - 1], dp[x + 1]) + 1);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
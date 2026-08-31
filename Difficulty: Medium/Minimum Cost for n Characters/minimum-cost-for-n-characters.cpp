class Solution {
public:
    int minCost(int n, int i, int d, int c) {

        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        for(int x = 1; x <= n; x++) {

            // Insert one character
            dp[x] = dp[x - 1] + i;

            if(x % 2 == 0) {
                // Directly copy-paste x/2 -> x
                dp[x] = min(dp[x], dp[x / 2] + c);
            }
            else {
                // Copy x/2 -> x-1, then insert
                dp[x] = min(dp[x], dp[x / 2] + c + i);

                // Copy (x+1)/2 -> x+1, then delete
                dp[x] = min(dp[x], dp[(x + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};
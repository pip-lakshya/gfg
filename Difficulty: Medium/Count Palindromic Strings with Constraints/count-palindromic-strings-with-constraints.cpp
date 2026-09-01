class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;

        long long ans = 0;
        long long ways = 1;

        for(int m = 0; 2 * m <= n; m++) {

            // Odd length = 2*m + 1
            if(2 * m + 1 <= n && m < k) {
                ans = (ans + ways * (k - m)) % MOD;
            }

            // Even length = 2*m
            if(m > 0 && m <= k && 2 * m <= n) {
                ans = (ans + ways) % MOD;
            }

            // P(k, m+1)
            if(m < k) {
                ways = (ways * (k - m)) % MOD;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        const long long MOD = 1000000007;
        int n = arr.size();

        vector<int> freq(n + 1, 0);

        for (int x : arr) {
            if (x >= 0 && x <= n)
                freq[x]++;
        }

        vector<long long> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        long long product = 1;
        int prefixCount = 0;

        for (int mex = 0; mex <= min(r, n); mex++) {

            if (mex > 0) {
                product = (product * (pow2[freq[mex - 1]] - 1 + MOD)) % MOD;
            }

            prefixCount += freq[mex];

            if (mex >= l) {
                int remaining = n - prefixCount;

                long long ways = (product * pow2[remaining]) % MOD;

                ans = (ans + ways) % MOD;
            }
        }

        return ans;
    }
};
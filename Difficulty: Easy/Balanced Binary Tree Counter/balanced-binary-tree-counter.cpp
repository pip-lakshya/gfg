class Solution {
  public:
    int countBT(int h) {
        long long mod = 1000000007;

        if (h <= 1) {
            return 1;
        }

        long long prev2 = 1; // T(0)
        long long prev1 = 1; // T(1)
        long long curr = 0;

        for (int i = 2; i <= h; ++i) {
            curr = (prev1 * prev1 + 2 * prev1 * prev2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

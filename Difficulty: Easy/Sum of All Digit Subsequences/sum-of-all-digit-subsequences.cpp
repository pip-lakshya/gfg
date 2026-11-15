class Solution {
  private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

  public:
    int subsequenceSum(string s) {
        long long MOD = 1e9 + 7;
        long long n = s.length();
        long long digit_sum = 0;

        for (char c : s) {
            digit_sum += (c - '0');
        }

        long long multiplier = power(2, n - 1, MOD);
        return (digit_sum % MOD * multiplier) % MOD;
    }
};

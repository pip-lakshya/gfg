class Solution {
  public:
      long long power(long long a, long long b) {
          long long ans = 1;

          while(b > 0) {
              if(b & 1)
                  ans = (ans * a) % 1000000007;

              a = (a * a) % 1000000007;
              b /= 2;
          }

          return ans;
      }

      int prefixStrings(int n) {
          const long long MOD = 1000000007;

          // factorials
          vector<long long> fact(2 * n + 1);

          fact[0] = 1;

          for(int i = 1; i <= 2 * n; i++) {
              fact[i] = (fact[i - 1] * i) % MOD;
          }

          // C(2n, n)
          long long comb = fact[2 * n];

          comb = (comb * power(fact[n], MOD - 2)) % MOD;
          comb = (comb * power(fact[n], MOD - 2)) % MOD;

          // Catalan = C(2n,n)/(n+1)
          long long ans = (comb * power(n + 1, MOD - 2)) % MOD;

          return ans;
      }
  };
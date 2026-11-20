class Solution {
  public:
    int minFlips(string s) {
        int n = s.size();
        int flips_0 = 0; // Flips needed to match "010101..."

        for (int i = 0; i < n; i++) {
            // Expected character at index i if starting with '0'
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                flips_0++;
            }
        }

        // Flips needed to match "101010..." is (n - flips_0)
        return min(flips_0, n - flips_0);
    }
};

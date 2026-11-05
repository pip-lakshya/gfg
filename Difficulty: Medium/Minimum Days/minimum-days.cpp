class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        using std::string;
        using std::vector;

        int n = s.length();
        int clashes = 0;

        // Count the initial number of adjacent duplicate pairs
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                clashes++;
            }
        }

        // If there are no initial clashes, 0 days are needed
        if (clashes == 0) {
            return 0;
        }

        // Process the removals day by day
        for (int day = 0; day < n; day++) {
            int idx = p[day];

            // Check left neighbor
            if (idx > 0 && s[idx] != '?' && s[idx] == s[idx - 1]) {
                clashes--;
            }

            // Check right neighbor
            if (idx < n - 1 && s[idx] != '?' && s[idx] == s[idx + 1]) {
                clashes--;
            }

            // Replace the character with '?'
            s[idx] = '?';

            // If all clashes are resolved, return the number of days spent
            if (clashes == 0) {
                return day + 1;
            }
        }

        return n;
    }
};

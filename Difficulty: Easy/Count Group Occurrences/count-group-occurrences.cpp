class Solution {
  public:
    int getCount(string &s, int k) {
        if (s.empty()) return 0;

        unordered_map<char, int> group_counts;

        // Process the first character
        char prev_char = s[0];
        group_counts[prev_char] = 1;

        // Traverse the string to find distinct groups
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] != prev_char) {
                group_counts[s[i]]++;
                prev_char = s[i];
            }
        }

        // Count characters that appear in exactly k groups
        int ans = 0;
        for (auto const& [character, count] : group_counts) {
            if (count == k) {
                ans++;
            }
        }

        return ans;
    }
};

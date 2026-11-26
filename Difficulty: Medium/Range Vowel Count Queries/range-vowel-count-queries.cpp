class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix sum of vowels
        for (int i = 0; i < n; i++) {
            bool isVowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                            s[i] == 'o' || s[i] == 'u');
            prefix[i + 1] = prefix[i] + (isVowel ? 1 : 0);
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};
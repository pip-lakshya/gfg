class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.size();

        // nextPos[i][c] = first position >= i having character c
        vector<array<int, 26>> nextPos(n + 1);

        nextPos[n].fill(-1);

        for (int i = n - 1; i >= 0; i--) {
            nextPos[i] = nextPos[i + 1];
            nextPos[i][s[i] - 'a'] = i;
        }

        string ans = "";

        for (const string &word : d) {
            int pos = 0;
            bool possible = true;

            for (char ch : word) {
                if (pos > n) {
                    possible = false;
                    break;
                }

                int nxt = nextPos[pos][ch - 'a'];

                if (nxt == -1) {
                    possible = false;
                    break;
                }

                pos = nxt + 1;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() &&
                     word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:

    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries,
                              int k) {

        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        // Function to count 1s in a rectangle
        auto getSum = [&](int r1, int c1, int r2, int c2) {

            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for(auto q : queries) {

            int i = q[0];
            int j = q[1];

            int maxRadius = min({
                i,
                j,
                n - 1 - i,
                m - 1 - j
            });

            int best = -1;

            for(int r = 0; r <= maxRadius; r++) {

                int top = i - r;
                int bottom = i + r;

                int left = j - r;
                int right = j + r;

                int ones = getSum(top, left, bottom, right);

                if(ones <= k) {
                    best = 2 * r + 1;
                }
                else {
                    break;
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};
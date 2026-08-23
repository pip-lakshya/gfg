class Solution {
public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        if(mat[r][c] == '#')
            return 0;

        // Minimum upward moves required to reach each cell
        vector<vector<int>> upUsed(
            n, vector<int>(m, INT_MAX)
        );

        queue<pair<int,int>> q;

        upUsed[r][c] = 0;
        q.push({r, c});

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            int currUp = upUsed[x][y];

            // Calculate downward moves used
            int currDown = currUp + (x - r);

            // UP
            if(x - 1 >= 0 &&
               mat[x - 1][y] == '.' &&
               currUp + 1 <= u &&
               currUp + 1 < upUsed[x - 1][y]) {

                upUsed[x - 1][y] = currUp + 1;
                q.push({x - 1, y});
            }

            // DOWN
            if(x + 1 < n &&
               mat[x + 1][y] == '.' &&
               currDown + 1 <= d &&
               currUp < upUsed[x + 1][y]) {

                upUsed[x + 1][y] = currUp;
                q.push({x + 1, y});
            }

            // LEFT
            if(y - 1 >= 0 &&
               mat[x][y - 1] == '.' &&
               currUp < upUsed[x][y - 1]) {

                upUsed[x][y - 1] = currUp;
                q.push({x, y - 1});
            }

            // RIGHT
            if(y + 1 < m &&
               mat[x][y + 1] == '.' &&
               currUp < upUsed[x][y + 1]) {

                upUsed[x][y + 1] = currUp;
                q.push({x, y + 1});
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(upUsed[i][j] != INT_MAX)
                    ans++;
            }
        }

        return ans;
    }
};
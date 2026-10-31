
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // memo[i][j][d] = final destination after mirror reflections
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );

        // d = 0 means moving right
        // d = 1 means moving down
        function<int(int,int,int)> resolve = [&](int i, int j, int d) -> int {
            if (i >= m || j >= n) return -1;

            if (grid[i][j] == 0)
                return i * n + j;

            if (memo[i][j][d] != -2)
                return memo[i][j][d];

            int ni = i + (d == 0);
            int nj = j + (d == 1);

            return memo[i][j][d] = resolve(ni, nj, 1 - d);
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0) continue;

                // Try moving right
                if (j + 1 < n) {
                    int dest;

                    if (grid[i][j + 1] == 1)
                        dest = resolve(i, j + 1, 0);
                    else
                        dest = i * n + j + 1;

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }

                // Try moving down
                if (i + 1 < m) {
                    int dest;

                    if (grid[i + 1][j] == 1)
                        dest = resolve(i + 1, j, 1);
                    else
                        dest = (i + 1) * n + j;

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

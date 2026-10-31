class Solution {
public:
    const int mod = 1e9 + 7;
    int rec(int i, int j, int f, int n, int m, vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if (dp[i][j][f] != -1)
            return dp[i][j][f];
        int right = 0, down = 0;
        if (grid[i][j] == 0) {
            down = rec(i + 1, j, 1, n, m, grid, dp);
            right = rec(i, j + 1, 0, n, m, grid, dp);
        } else {
            if (f == 1) {
                right = rec(i, j + 1, 0, n, m, grid, dp);
            } else {
                down = rec(i + 1, j, 1, n, m, grid, dp);
            }
        }
        return dp[i][j][f] = (down + right) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1)));
        return rec(0, 0, 0, n, m, grid, dp);
    }
};
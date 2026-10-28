class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n)
        );
        dp[0][0].insert(grid[0][0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    for (int x : dp[i - 1][j])
                        dp[i][j].insert(x ^ grid[i][j]);
                }
                if (j > 0) {
                    for (int x : dp[i][j - 1])
                        dp[i][j].insert(x ^ grid[i][j]);
                }
            }
        }
        return *min_element( dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end() );
    }
};



// class Solution {
// public:
//     int ans = INT_MAX;
//     void solve(vector<vector<int>>& grid, int i, int j, int xr) {
//         int m = grid.size(), n = grid[0].size();
//         xr ^= grid[i][j];
//         if (i == m - 1 && j == n - 1) {
//             ans = min(ans, xr);
//             return;
//         }
//         if (i + 1 < m)
//             solve(grid, i + 1, j, xr);                               //bruteforce approach 
//         if (j + 1 < n)
//             solve(grid, i, j + 1, xr);
//     }
//     int minCost(vector<vector<int>>& grid) {
//         solve(grid, 0, 0, 0);
//         return ans;
//     }
// };

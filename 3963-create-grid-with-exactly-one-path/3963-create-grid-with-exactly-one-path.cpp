class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));         //this step takes O(m*n) time
        for (int i = 0; i < m; i++) {
            grid[i][0] = '.';
        }
        for (int j = 0; j < n; j++) {
            grid[m - 1][j] = '.';
        }
        return grid;
    }
};
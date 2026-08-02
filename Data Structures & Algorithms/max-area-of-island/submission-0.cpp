class Solution {
   public:
    int rows, cols, res = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) return 0;
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) +
                   dfs(grid, r, c - 1);
        }
        return 0;
    }
};

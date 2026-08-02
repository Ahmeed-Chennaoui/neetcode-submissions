class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, rows = grid.size(), cols = grid[0].size(), fresh = 0;
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        if(!fresh)return 0;
        while (!q.empty() && fresh) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (grid[x][y] == 1) fresh--;
                visit[x][y] = true;
                for (int j = 0; j < 4; j++) {
                    int r = x + directions[j][0], c = y + directions[j][1];
                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1 || visit[r][c])
                        continue;
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
            time++;
        }
        return (fresh == 0) ? time - 1 : -1;
    }
};

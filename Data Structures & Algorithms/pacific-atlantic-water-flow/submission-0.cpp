class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> pacQueue, atlQueue;

        for (int c = 0; c < COLS; ++c) {
            pacQueue.push({0, c});
            atlQueue.push({ROWS - 1, c});
        }
        for (int r = 0; r < ROWS; ++r) {
            pacQueue.push({r, 0});
            atlQueue.push({r, COLS - 1});
        }

        bfs(heights, pacQueue, pac);
        bfs(heights, atlQueue, atl);
        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& ocean) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [x, y] = q.front();
                ocean[x][y] = true;
                q.pop();
                for (auto [dr, dc] : directions) {
                    int r = x + dr, c = y + dc;
                    if (r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size() &&
                        !ocean[r][c] && heights[r][c] >= heights[x][y]) {
                        q.push({r, c});
                    }
                }
            }
        }
    }
};

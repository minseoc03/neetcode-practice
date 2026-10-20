class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = static_cast<int>(grid.size());
        int COL = static_cast<int>(grid[0].size());

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int size = static_cast<int>(q.size());

            for (int k = 0; k < size; ++k) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) {
                        continue;
                    }

                    if (grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    --fresh;
                    q.push({nr, nc});
                }
            }

            ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};
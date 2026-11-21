class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        vector<vector<bool>> visited(
            ROW, vector<bool>(COL, false)
        );

        queue<pair<int, int>> q_first_island;
        bool found = false;
        for (int i = 0; i < ROW && !found; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 1) {
                    q_first_island.push({i, j});
                    found = true;
                    visited[i][j] = true;
                    break;
                }
            }
        }

        queue<pair<int, int>> q;
        while (!q_first_island.empty()) {
            pair<int, int> curr = q_first_island.front();
            q_first_island.pop();

            bool is_perimeter = false;

            for (int i = 0; i < 4; i++) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];

                if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) continue;
                if (grid[nr][nc] == 0) {
                    is_perimeter = true;
                    continue;
                }
                if (visited[nr][nc]) continue;
                q_first_island.push({nr, nc});
                visited[nr][nc] = true;

            }
            if (is_perimeter) q.push(curr);
        }

        int counter = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nr = curr.first + dr[j];
                    int nc = curr.second + dc[j];
                    if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) continue;
                    if (visited[nr][nc]) continue;
                    if (grid[nr][nc] == 1) {
                        if (!visited[nr][nc]) return counter;
                        continue;
                    }
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            counter++;
        }
        return -1;
    }
};
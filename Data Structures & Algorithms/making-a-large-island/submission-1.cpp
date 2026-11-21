class Solution {
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<int> islandSize;
        int islandNum = 2;
        int maxSize = 0;

        bool is_all_one = true, is_all_zero = true;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 1) {
                    is_all_zero = false;
                }
                if (grid[i][j] == 0) {
                    is_all_one = false;
                }
            }
        }
        if (is_all_one) return (int)grid.size() * (int)grid[0].size();
        if (is_all_zero) return 1;

        // annotate island number
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, islandSize, i, j, islandNum);
                    islandNum++;
                }
            }
        }

        // traverse ocean
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 0) {
                    int currSize = 0;
                    unordered_set<int> seen;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) continue;
                        if (seen.find(grid[nr][nc]) != seen.end()) continue;
                        if (grid[nr][nc] != 0 && grid[nr][nc] != 1) {
                            currSize += islandSize[grid[nr][nc] - 2];
                            seen.insert(grid[nr][nc]);
                        }
                    }
                    currSize += 1;
                    maxSize = max(maxSize, currSize);
                }
            }
        }
        return maxSize;
    }
private:
    void bfs(vector<vector<int>>& grid, vector<int>& islandSize, int r, int c, int num) {
        queue<pair<int, int>> q;
        int currentSize = 1;
        q.push({r, c});
        grid[r][c] = num;
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
                if (grid[nr][nc] == 0) continue;
                if (grid[nr][nc] != 1) continue;
                q.push({nr, nc});
                grid[nr][nc] = num;
                currentSize++;
            }
        }
        islandSize.push_back(currentSize);
    }
};

class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int islands = 0;
         for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
        
    }
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row,col});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};

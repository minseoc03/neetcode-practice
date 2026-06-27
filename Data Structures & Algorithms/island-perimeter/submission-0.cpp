class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited (row, vector<bool>(col, false));
        int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int perimeter = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        for (auto& d : direction) {
                            int nx = r + d[0], ny = c + d[1];
                            if (nx < 0 || nx >= row || ny < 0 || ny >= col || grid[nx][ny] == 0) {
                                perimeter++;
                            }
                            else if (!visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                    return perimeter;
                }
            }
        }
        return 0;
    }
};
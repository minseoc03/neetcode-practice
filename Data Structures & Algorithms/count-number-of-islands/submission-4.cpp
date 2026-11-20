class Solution {
public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        int res = 0;

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
private:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                if (nr < 0 || nc < 0 || 
                    nr >= grid.size() || 
                    nc >= grid[0].size() || 
                    grid[nr][nc] == '0'
                    ) 
                {
                    continue;
                }
                grid[nr][nc] = '0';
                q.push({nr, nc}); 
            }
        }
    }
};

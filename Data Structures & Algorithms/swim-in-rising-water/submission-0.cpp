class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         // 1. DFS w/ binary search
//         int n = grid.size();
//         vector<vector<bool>> visit(n, vector<bool>(n, false));
//         int minH = grid[0][0];
//         int maxH = grid[0][0];
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < n; col++) {
//                 maxH = max(maxH, grid[row][col]);
//                 minH = min(minH, grid[row][col]);
//             }
//         }

//         int l = minH, r = maxH;
//         while (l < r) {
//             int m = (l + r) >> 1;
//             if (dfs(grid, visit, 0, 0, m)) r = m;
//             else l = m + 1;
//             for (int row = 0; row < n; row++) {
//                 fill(visit[row].begin(), visit[row].end(), false);
//             }
//         }
//         return r;
//     }
// private:
//     bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int t) {
//         if (r < 0 || c < 0 || r >= grid.size() || c >= grid.size() || visit[r][c] || grid[r][c] > t) {
//             return false;
//         }
//         if (r == grid.size() - 1 && c == grid.size() - 1) {
//             return true;
//         }
//         visit[r][c] = true;
//         return dfs(grid, visit, r + 1, c, t) || dfs(grid, visit, r, c + 1, t) || dfs(grid, visit, r - 1, c, t) || dfs(grid, visit, r, c - 1, t);
//     }

public:
    int swimInWater(vector<vector<int>>& grid) {
        // 2. dijkstra
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0,0});

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            if (r == N - 1 && c == N - 1) {
                return t;
            }
            for (const auto& dir : directions) {
                int neiR = r + dir[0];
                int neiC = c + dir[1];
                if (neiR < 0 || neiC < 0 || neiR == N || neiC == N || visit.count({neiR, neiC})) {
                    continue;
                }
                visit.insert({neiR, neiC});
                minHeap.push(
                    {max(t, grid[neiR][neiC]), neiR, neiC}
                );
            }
        }
        return N * N;
    }
};

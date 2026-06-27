class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int land = 0, adj = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j]) {
                    ++land;
                    if (i + 1 < row && grid[i+1][j]) ++adj;
                    if (j + 1 < col && grid[i][j+1]) ++adj;
                }
        return 4 * land - 2 * adj;
    }
};
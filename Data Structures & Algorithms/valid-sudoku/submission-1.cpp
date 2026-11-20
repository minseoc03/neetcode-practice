class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;

                int squareIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    squares[squareIndex].count(num)) {
                    return false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                squares[squareIndex].insert(num);
            }
        }

        return true;
    }
};
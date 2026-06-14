class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0;
        int r = row * col - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int _row = mid / col;
            int _col = mid % col;
            int val = matrix[_row][_col];
            if (target == val) {
                return true;
            }
            if (target > val) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};

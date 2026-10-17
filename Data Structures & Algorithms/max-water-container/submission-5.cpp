class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;
        while (l < r) {
            int curr = min(heights[l], heights[r]) * (r - l);
            area = max(curr, area);
            if (heights[l] < heights[r]) {
                l++;
            }
            else if (heights[l] > heights[r]) {
                r--;
            }
            else {
                l++;
                r--;
            }
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int lo = 0;
        int hi = static_cast<int>(heights.size()) - 1;
        while (lo < hi) {
            area = max(min(heights[lo], heights[hi]) * abs(hi - lo), area);
            if (heights[lo] < heights[hi]) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return area;
    }
};

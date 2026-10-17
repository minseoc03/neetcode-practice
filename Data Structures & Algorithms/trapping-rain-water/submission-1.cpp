class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; // edge case
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int res = 0;
        while (l < r) {
            if (maxL < maxR) {
                l++;
                res += max(0, maxL - height[l]);
                maxL = max(maxL, height[l]);
            }
            else {
                r--;
                res += max(0, maxR - height[r]);
                maxR = max(maxR, height[r]);
            }
        }
        return res;
    }
};

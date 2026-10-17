class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {index, height}
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxStart = 0;
        for (const auto& interval : intervals) {
            maxStart = max(maxStart, interval[0]);
        }

        vector<int> mp(maxStart + 1, -1);

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(mp[start], end);
        }

        vector<vector<int>> res;
        int have = -1;
        int intervalStart = -1;

        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != -1) {
                if (intervalStart == -1) {
                    intervalStart = i;
                }
                have = max(have, mp[i]);
            }

            if (have == i) {
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            res.push_back({intervalStart, have});
        }

        return res;
    }
};
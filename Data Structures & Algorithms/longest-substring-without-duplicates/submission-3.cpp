class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(begin(last), end(last), -1);
        int l = 0;
        int res = 0;
        for (int r = 0; r < static_cast<int>(s.length()); ++r) {
            unsigned char c = s[r];
            if (last[c] >= l)
                l = last[c] + 1;
            last[c] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};

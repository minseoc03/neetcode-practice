class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, int> mp;
        mp.reserve(s.size());
        int l = 0, res = 0;
        for (int r = 0; r < static_cast<int>(s.size()); ++r) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};

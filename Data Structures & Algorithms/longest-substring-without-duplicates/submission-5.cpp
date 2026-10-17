class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window : move l one by one 

        // unordered_set<char> charSet;
        // int l = 0;
        // int res = 0;
        // for (int r = 0; r < s.size(); ++r) {
        //     while (charSet.find(s[r]) != charSet.end()) {
        //         charSet.erase(s[l]);
        //         l++;
        //     }
        //     charSet.insert(s[l]);
        //     res = max(res, r - l + 1);
        // }
        // return res;

        // sliding window : jump l to right after redundant character
        unordered_map<char, int> indexMap; // key = char, value = index of char last seen
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (indexMap.find(s[r]) != indexMap.end()) {
                l = max(l, indexMap[s[r]] + 1);
            }
            indexMap[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};

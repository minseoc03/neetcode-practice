class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0;
        int res = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while (r-l+1 - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(r-l+1, res);
        }
        return res;
    }
};

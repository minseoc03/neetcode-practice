class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> count{};
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (auto i : count) {
            if (i != 0) return false;
        }
        return true;
    }
};

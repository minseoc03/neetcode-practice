class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        array<int, 26> count{};
        for (size_t i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (auto i : count) {
            if (i != 0)
                return false;
        }
        return true;
    }
};

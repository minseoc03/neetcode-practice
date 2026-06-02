class Solution {
public:

    string encode(vector<string>& strs) {
        size_t total = 0;
        for (const auto& s : strs)
            total += s.size() + 11;
        string res;
        res.reserve(total);
        for (const string& s : strs) {
            res += to_string(s.size());
            res += '#';
            res += s;
        }
        return res;
    }

    vector<string> decode(const string& s) {
        vector<string> res;
        size_t i = 0;
        size_t n = s.size();
        while (i < n) {
            int length = 0;
            while(s[i] != '#') {
                length = length * 10 + (s[i++] - '0');
            }
            ++i;
            res.emplace_back(s, i, length);
            i += length;
        }
        return res;
    }
};

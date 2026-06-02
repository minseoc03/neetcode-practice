class Solution {
    struct ArrayHash {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;
            for (int x : a) {
                h = h * 31 + static_cast<size_t>(x);
            }
            return h;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> res;
        // for (const auto& s : strs) {
        //     vector<int> count(26, 0);
        //     for (char c : s) {
        //         count[c - 'a']++;
        //     }
        //     string key = to_string(count[0]);
        //     for (int i = 1; i < 26; ++i) {
        //         key += ',' + to_string(count[i]);
        //     }
        //     res[key].push_back(s);
        // }
        // vector<vector<string>> result;
        // for (const auto& pair : res) {
        //     result.push_back(pair.second);
        // }
        // return result;
        unordered_map<array<int, 26>, vector<string>, ArrayHash> res;
        res.reserve(strs.size());
        for (const auto& s : strs) {
            array<int, 26> count{};
            for (char c : s) {
                count[c - 'a']++;
            }
            res[count].push_back(s);
        }
        vector<vector<string>> output;
        output.reserve(res.size());
        for (auto& [key, value] : res) {
            output.push_back(std::move(value));
        }
        return output;
    }
};
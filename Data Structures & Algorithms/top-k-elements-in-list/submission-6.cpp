class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const auto& i : nums) {
            count[i]++;
        }
        vector<vector<int>> freq (nums.size() + 1);
        for (auto &[k, f] : count) {
            freq[f].push_back(k);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (auto n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};

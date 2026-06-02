class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count.reserve(nums.size());
        for (int n : nums) {
            count[n]++;
        }
        vector<vector<int>> freq (nums.size() + 1);
        for (auto& [k, f] : count) {
            freq[f].push_back(k);
        }
        vector<int> res;
        res.reserve(nums.size());
        for (int i = static_cast<int>(freq.size() - 1); i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == static_cast<size_t>(k)) {
                    return res;
                }
            }
        }
        return res;
    }
};

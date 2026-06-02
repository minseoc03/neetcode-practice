class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m.reserve(nums.size());
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int comp = target - nums[i];
            auto it = m.find(comp);
            if (it != m.end())
                return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mm;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int comp = target - nums[i];
            if (mm.find(comp) != mm.end())
                return {mm[comp], i};
            mm[nums[i]] = i;
        }
    }
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        seen.reserve(nums.size());
        for (auto i : nums) {
            if(!seen.insert(i).second)
                return true;
        }
        return false;
    }
};
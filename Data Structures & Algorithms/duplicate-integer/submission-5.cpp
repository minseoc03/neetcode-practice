class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;
        for (auto i : nums) {
            int before = seen.size();
            seen.insert(i);
            if (before == seen.size()) return true;
        }
        return false;
    }
};
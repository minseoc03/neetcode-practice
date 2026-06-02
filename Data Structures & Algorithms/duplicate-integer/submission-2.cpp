class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> a;
        for (auto i : nums) {
            a.insert(i);
        }
        if (a.size() != nums.size())
            return true;
        return false;
    }
};
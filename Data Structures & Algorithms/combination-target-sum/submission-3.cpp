class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(nums, target, res, comb, 0, 0);
        return res;
    }

    void backtrack(
        const vector<int>& nums,
        int target,
        vector<vector<int>>& res,
        vector<int>& comb,
        int sum,
        int start
    ) {
        if (sum == target) {
            res.push_back(comb);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            comb.push_back(nums[i]);
            backtrack(nums, target, res, comb, sum + nums[i], i);
            comb.pop_back();
        }
    }
};
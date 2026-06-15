class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, target, 0, subset, res);
        return res;
    }
private:
    void dfs(int i, vector<int>& nums, int target, int total, vector<int>& subset, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(subset);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            if (total + nums[j] > target)
                return;
            subset.push_back(nums[j]);
            dfs(j, nums, target, total + nums[j], subset, res);
            subset.pop_back();
        }
    }
};

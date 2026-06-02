class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1;
            int hi = static_cast<int>(nums.size()) - 1;
            int target = -nums[i];
            while (lo < hi) {
                if (nums[lo] + nums[hi] == target) {
                    res.push_back({nums[lo], nums[hi], nums[i]});
                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;
                    lo++; hi--;
                }
                else if (target > nums[lo] + nums[hi])
                    lo++;
                else
                    hi--;      
            }
        }
        return res;
    }
};

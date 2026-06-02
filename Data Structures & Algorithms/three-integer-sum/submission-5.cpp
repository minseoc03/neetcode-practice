class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n - 2; ++i) {                       // i+2 유효하도록 n-2
            if (nums[i] > 0) break;                             // 양수면 끝
            if (i > 0 && nums[i] == nums[i - 1]) continue;      // 중복 i skip

            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;     // 최소합 prune
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;  // 최대합 prune

            int lo = i + 1, hi = n - 1, target = -nums[i];
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];                  // 한 번만 계산
                if (sum == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;   // 중복 lo skip
                    while (lo < hi && nums[hi] == nums[hi - 1]) --hi;   // 중복 hi skip
                    ++lo; --hi;
                }
                else if (sum < target) ++lo;                    // 너무 작음 → 키운다
                else                   --hi;                    // 너무 큼  → 줄인다
            }
        }
        return res;                                             // 루프 밖
    }
};
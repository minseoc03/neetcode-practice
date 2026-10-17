class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // pruning
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;
            
            int target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int curr = nums[l] + nums[r];
                if (curr == target) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) {
                        cout << l << endl;
                        l++;
                    }
                    while (l < r && nums[r] == nums[r-1]) {
                        cout << r << endl;
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (curr < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return result;
    }
};

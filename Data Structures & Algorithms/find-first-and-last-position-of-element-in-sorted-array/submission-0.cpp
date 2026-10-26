class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int l = 0;
        int r = nums.size() - 1;
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                result = mid;
                
                if (findFirst) {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }

        return result;
    }
};
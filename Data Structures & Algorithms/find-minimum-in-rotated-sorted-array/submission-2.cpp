class Solution {
public:
    int findMin(vector<int> &nums) {
        // binary search
        // set l and r, and calculate mid
        // if mid is greater than r, then pivot is at right half
        // move l to mid
        // vice versa, if mid is smaller than r, then pivot is at left half
        // move r to mid - 1
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};

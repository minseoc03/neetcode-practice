class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else 
                l = mid + 1;
        }
        // now l = pivot
        int pivot = l;
        l = 0;
        r = n - 1;
        if (target >= nums[pivot] && target <= nums[r])
            l = pivot;
        else
            r = pivot - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
                return mid;
            if (target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};

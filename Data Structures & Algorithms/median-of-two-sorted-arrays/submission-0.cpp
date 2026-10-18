class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;
        vector<int>& b = nums2;

        int total = a.size() + b.size();
        int half = (total + 1) / 2; // add one, so left + 1 == right
        if (a.size() > b.size()) swap(a,b); // keep A smaller array

        int l = 0;
        int r = a.size();

        while (l <= r) {
            int i = (l + r) / 2; // i = # of Aleft
            int j = half - i; // j = # of Bleft

            int aLeft = (i > 0) ? a[i-1] : INT_MIN;
            int aRight = (i < a.size()) ? a[i] : INT_MAX;
            int bLeft = (j > 0) ? b[j-1] : INT_MIN;
            int bRight = (j < b.size()) ? b[j] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2 != 0) {
                    return max(aLeft, bLeft);
                }
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            }
            else if (aLeft > bRight) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return -1;
    }
};

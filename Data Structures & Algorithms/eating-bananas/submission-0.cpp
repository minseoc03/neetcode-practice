class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int hr = 0;
            for (const auto& b : piles) {
                hr += ceil(static_cast<double>(b)/mid);
            }
            if (hr <= h) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};

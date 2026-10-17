class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;
        while (l < r) {
            int mid = (l + r) / 2;
            int h_prime = 0;
            for (const int& p : piles) {
                h_prime += ceil(static_cast<double>(p)/mid);
            }
            if (h_prime > h) l = mid + 1;
            else {
                r = mid;
                res = r;
            }
        }
        return res;
    }
};

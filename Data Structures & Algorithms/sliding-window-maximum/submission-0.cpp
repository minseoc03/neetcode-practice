class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            // if incoming value is greater than the current maximum (= queue.front()),
            // current maximum is impossible to be maximum again because
            // incoming value will survive longer than current maximum
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            // evict out if current window size is k
            while (!q.empty() && q.front() <= r - k) {
                q.pop_front();
            }

            // insert new value
            q.push_back(r);

            // store result
            if (r >= k - 1) {
                res.push_back(nums[q.front()]);
            }

            r++;
        }
        return res;
    }
};

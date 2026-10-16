class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int n : numSet) {
            // start of one consecutive set
            if (numSet.find(n - 1) == numSet.end()) {
                int length = 1;
                // keep find the consecutive numbers
                while (numSet.find(n + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

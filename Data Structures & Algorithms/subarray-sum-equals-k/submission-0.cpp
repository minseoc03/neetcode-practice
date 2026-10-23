class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix[j] - prefix[i] = sum(i+1 ... j)
        unordered_map<int, int> prefixCount; // key = prefixSum, value = count
        int currSum = 0;
        int res = 0;
        prefixCount[0] = 1;
        for (int& n : nums) {
            currSum += n;
            int diff = currSum - k;
            res += prefixCount[diff];
            prefixCount[currSum]++;
        }
        return res;
    }
};
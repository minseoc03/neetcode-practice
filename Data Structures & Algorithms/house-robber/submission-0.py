class Solution:
    def rob(self, nums: List[int]) -> int:
        #OPT(i) = maximum amount of money I robbed at ith house
        #OPT(i) = max(OPT(i-1), nums[i] + OPT(i-2))
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        a, b = 0, nums[0] # a = OPT(i-2), b = OPT(i-1)
        for i in range(1, len(nums)):
            a, b = b, max(b, nums[i] + a)
        return b
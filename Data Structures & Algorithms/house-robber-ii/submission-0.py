class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        def rob_linear(arr):
            a, b = 0, 0
            for x in arr:
                a, b = b, max(b, x + a)
            return b
        
        return max(rob_linear(nums[:-1]), rob_linear(nums[1:]))
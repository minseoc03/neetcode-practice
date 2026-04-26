class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def linear_dp(nums):
            dp = [0 for _ in range(len(nums) + 2)]
            for i in range(2, len(nums) + 2):
                dp[i] = max(dp[i-1], dp[i-2] + nums[i-2])
            
            return dp[-1]
        
        return max(linear_dp(nums[0 : -1]), linear_dp(nums[1 :]))
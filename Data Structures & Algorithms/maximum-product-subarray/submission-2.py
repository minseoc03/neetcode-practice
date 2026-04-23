class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        opt = [0 for _ in range(len(nums))]
        min_arr = [0 for _ in range(len(nums))]
        max_arr = [0 for _ in range(len(nums))]

        opt[0] = nums[0]
        min_arr[0] = nums[0]
        max_arr[0] = nums[0]
        for i in range(1, len(nums)):
            min_arr[i] = min(min_arr[i-1] * nums[i], 
                             max_arr[i-1] * nums[i],
                             nums[i])
            max_arr[i] = max(min_arr[i-1] * nums[i], 
                             max_arr[i-1] * nums[i],
                             nums[i])
            opt[i] = max(min_arr[i-1] * nums[i], max_arr[i-1] * nums[i], nums[i])
        return max(opt)
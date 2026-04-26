class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            lo = i + 1
            hi = len(nums) - 1
            target = -nums[i]
            while lo < hi:
                if nums[lo] + nums[hi] == target:
                    res.append([nums[i], nums[lo], nums[hi]])
                    # remove duplicates
                    while lo < hi and nums[lo] == nums[lo + 1]:
                        lo += 1
                    while lo < hi and nums[hi] == nums[hi - 1]:
                        hi -= 1
                    lo += 1
                    hi -= 1
                elif nums[lo] + nums[hi] > target:
                    hi -= 1
                else:
                    lo += 1
        
        return res
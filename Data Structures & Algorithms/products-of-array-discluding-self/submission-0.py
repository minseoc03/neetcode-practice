import math

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = math.prod(nums)
        res = []

        for n in nums:
            if n == 0:
                i = nums.index(n)
                res.append(math.prod(nums[0 : i]) * math.prod(nums[i + 1 : ]))
            else:
                res.append(prod // n)

        return res

        
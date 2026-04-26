class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        a = set(nums)
        res = 0
        for n in a:
            if n - 1 not in a:  # sequence 시작점
                length = 1
                while n + length in a:
                    length += 1
                res = max(res, length)
        return res
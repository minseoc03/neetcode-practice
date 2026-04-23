from collections import defaultdict
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        opt = [0 for _ in range(len(nums))]
        graph = defaultdict(list)
        for i in range(len(nums)):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    graph[i].append(j)
        
        opt[0] = 1
        for i in range(1, len(nums)):
            cnt = 0
            for j in graph[i]:
                if cnt < opt[j]:
                    cnt = opt[j]
            opt[i] = cnt + 1
        
        return max(opt)

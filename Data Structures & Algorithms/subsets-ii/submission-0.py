class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        def dfs(idx, cur):
            res.append(cur.copy())
            for i in range(idx, len(nums)):
                if i > idx and nums[i] == nums[i-1]:
                    continue
                cur.append(nums[i])
                dfs(i+1, cur)
                cur.pop()
        
        dfs(0, [])
        return res
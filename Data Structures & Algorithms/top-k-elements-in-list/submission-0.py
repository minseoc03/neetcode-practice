from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num = Counter(nums)
        tmp = num.most_common(k)
        res = []
        for i in tmp:
            res.append(i[0])
        return res
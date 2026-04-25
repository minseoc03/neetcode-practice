class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        res = []
        bucket = [[] for _ in range(len(nums) + 1)]

        for n, freq in cnt.items():
            bucket[freq].append(n)
        
        for i in range(len(bucket) - 1, -1, -1):
            for n in bucket[i]:
                res.append(n)
                if len(res) == k:
                    return res
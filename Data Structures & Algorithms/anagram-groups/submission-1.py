class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen = defaultdict(list)
        for i in strs:
            key = tuple(sorted(i))
            seen[key].append(i)
        
        return list(seen.values())

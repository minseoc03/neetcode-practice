class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = defaultdict(int)
        l = 0
        max_freq = 0
        res = 0
        for right in range(len(s)):
            freq[s[right]] += 1
            max_freq = max(max_freq, freq[s[right]])
            
            while (right - l + 1) - max_freq > k:
                freq[s[l]] -= 1
                l += 1
            
            res = max(res, right-l+1)
        
        return res
            
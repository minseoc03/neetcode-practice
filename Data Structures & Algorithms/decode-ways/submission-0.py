class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        a, b = 1, 1  # dp[i-2], dp[i-1]
        for i in range(1, len(s)):
            cur = 0
            if s[i] != '0':          # 한 자리로 디코딩 가능
                cur += b
            if 10 <= int(s[i-1:i+1]) <= 26:  # 두 자리로 디코딩 가능
                cur += a
            a, b = b, cur
        return b
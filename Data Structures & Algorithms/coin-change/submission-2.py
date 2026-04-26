class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf') for _ in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            min_num = float('inf')
            for b in coins:
                if i >= b:
                    dp[i] = dp[i-b] + 1
                if min_num > dp[i]:
                    min_num = dp[i]
            dp[i] = min_num
        
        if dp[amount] == float('inf'):
            return -1
        return dp[amount]
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        opt = [float('inf') for _ in range(amount + 1)]
        opt[0] = 0
        for i in range(1, amount+1):
            min = float('inf')
            for j in coins:
                if i >= j:
                    opt[i] = opt[i - j] + 1
                if min > opt[i]:
                    min = opt[i]
            opt[i] = min
        
        if opt[amount] == float('inf'):
            return -1
        return opt[amount]
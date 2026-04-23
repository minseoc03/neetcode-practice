class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        opt = [[0 for _ in range(n)] for _ in range(m)]
        opt[0][0] = 1
        for i in range(1, m):
            opt[i][0] = opt[i-1][0]
        for j in range(1, n):
            opt[0][j] = opt[0][j-1]
        for i in range(1, m):
            for j in range(1, n):
                opt[i][j] = opt[i-1][j] + opt[i][j-1]
        
        return opt[m-1][n-1]

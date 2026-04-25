class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights) # column
        n = len(heights[0]) # row
        pacific = set()
        atlantic = set()

        def dfs(r, c, visited):
            visited.add((r, c))
            for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                nr, nc = r + dr, c + dc

                if (0 <= nr < m and
                    0 <= nc < n and
                    (nr, nc) not in visited and
                    heights[r][c] <= heights[nr][nc]):

                    dfs(nr, nc, visited)
            
        for i in range(m):
            dfs(i, 0, pacific)
            dfs(i, n-1, atlantic)
        for j in range(n):
            dfs(0, j, pacific)
            dfs(m-1, j, atlantic)
        
        return [[r, c] for r,c in pacific & atlantic]
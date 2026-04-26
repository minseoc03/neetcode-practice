class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific = set()
        atlantic = set()
        pair = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        r = len(heights)
        c = len(heights[0])

        def dfs(i, j, visited):
            if i < 0 or i >= r or j < 0 or j >= c or (i,j) in visited:
                return
            visited.add((i,j))
            for dr, dc in pair:
                nr, nc = i + dr, j + dc
                if 0 <= nr < r and 0 <= nc < c and heights[nr][nc] >= heights[i][j]:
                    dfs(nr, nc, visited)
        
        for i in range(c):
            dfs(0, i, pacific)
            dfs(r-1, i, atlantic)
        
        for j in range(r):
            dfs(j, 0, pacific)
            dfs(j, c-1, atlantic)
        
        return [[r, c] for r,c in pacific & atlantic]

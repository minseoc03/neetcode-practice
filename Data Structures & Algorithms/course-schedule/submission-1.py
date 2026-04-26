class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for i in prerequisites:
            adj[i[0]].append(i[1])
        
        WHITE, GRAY, BLACK = 0, 1, 2
        color = [WHITE] * numCourses
        hasCycle = False

        def dfs(n):
            color[n] = GRAY
            for nei in adj[n]:
                if color[nei] == GRAY:
                    return False
                if color[nei] == WHITE:
                    if not dfs(nei):
                        return False
            color[n] = BLACK
            return True
        
        for i in range(numCourses):
            if color[i] == WHITE:
                if not dfs(i):
                    return False
        
        return True
        
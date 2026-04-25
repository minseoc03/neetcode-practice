from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for a in prerequisites:
            graph[a[0]].append(a[1])
        
        WHITE, GRAY, BLACK = 0, 1, 2
        color = [WHITE] * numCourses

        def dfs(node):
            color[node] = GRAY
            for nei in graph[node]:
                if color[nei] == GRAY:
                    return False
                if color[nei] == WHITE:
                    if not dfs(nei):
                        return False
            color[node] = BLACK
            return True
        
        for i in range(numCourses):
            if color[i] == WHITE:
                if not dfs(i):
                    return False
        
        return True
        

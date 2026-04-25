from collections import defaultdict
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = set()
        graph = defaultdict(list)
        count = 0
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        
        def dfs(node):
            visited.add(node)
            for nei in graph[node]:
                if nei not in visited:
                    dfs(nei)
        
        for i in range(n):
            if i not in visited:
                dfs(i)
                count += 1
    
        return count
        

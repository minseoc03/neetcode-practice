from collections import defaultdict
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for i in edges:
            adj[i[0]].append(i[1])
            adj[i[1]].append(i[0])
        visited = set()

        if len(edges) != n - 1:
            return False
        
        def dfs(node, visited):
            visited.add(node)
            for nei in adj[node]:
                if nei not in visited:
                    dfs(nei, visited)
        
        dfs(0, visited)
        if len(visited) != n:
            return False
        return True

        

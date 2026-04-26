class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        
        visited = set()
        def dfs(n, visited):
            visited.add(n)
            for nei in graph[n]:
                if nei not in visited:
                    dfs(nei, visited)
        
        dfs(0, visited)
        
        return len(visited) == n and len(edges) == n-1
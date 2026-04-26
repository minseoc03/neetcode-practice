class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = set()
        count = 0
        graph = defaultdict(list)
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        def dfs(n, visited):
            visited.add(n)
            for nei in graph[n]:
                if nei not in visited:
                    dfs(nei, visited)
        
        for i in range(n):
            if i not in visited:
                dfs(i, visited)
                count += 1
        
        return count
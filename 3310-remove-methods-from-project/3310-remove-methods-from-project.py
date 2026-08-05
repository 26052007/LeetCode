class Solution:
    def remainingMethods(self, n: int, k: int, invocations: list[list[int]]) -> list[int]:
        from collections import defaultdict, deque

        graph = defaultdict(list)
        for u, v in invocations:
            graph[u].append(v)

        suspicious = set()
        queue = deque([k])
        suspicious.add(k)

        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if neighbor not in suspicious:
                    suspicious.add(neighbor)
                    queue.append(neighbor)

        for u, v in invocations:
            if u not in suspicious and v in suspicious:
                return list(range(n))

        return [i for i in range(n) if i not in suspicious]
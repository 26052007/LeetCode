import heapq

class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free_servers = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(free_servers)
        
        busy_servers = []
        ans = []
        current_time = 0
        
        for j, task_time in enumerate(tasks):
            current_time = max(current_time, j)
            
            if not free_servers and busy_servers[0][0] > current_time:
                current_time = busy_servers[0][0]
                
            while busy_servers and busy_servers[0][0] <= current_time:
                free_time, weight, index = heapq.heappop(busy_servers)
                heapq.heappush(free_servers, (weight, index))
                
            weight, index = heapq.heappop(free_servers)
            ans.append(index)
            heapq.heappush(busy_servers, (current_time + task_time, weight, index))
            
        return ans
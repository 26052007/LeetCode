class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        arr = [(x, i) for i, x in enumerate(nums)]
        arr.sort(key=lambda item: (sum(int(d) for d in str(item[0])), item[0]))
        
        n = len(nums)
        visited = [False] * n
        swaps = 0
        
        for i in range(n):
            if visited[i] or arr[i][1] == i:
                continue
            
            cycle = 0
            j = i
            while not visited[j]:
                visited[j] = True
                j = arr[j][1]
                cycle += 1
            
            if cycle > 1:
                swaps += cycle - 1
                
        return swaps
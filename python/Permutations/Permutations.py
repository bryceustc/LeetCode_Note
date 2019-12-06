
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res=[]
        if n == 0:
            return res
        out = []
        visited = [0 for i in range(n)]
        self.DFS(nums,0,visited,out,res)
        return res
    def DFS(self, nums: List[int], level : int, visited: List[int], out: List[int], res: List[List[int]]):
        n = len(nums)
        if level == n:
            res.append(out[:])
            return
        for i in range (0,n):
            if visited[i] == 1:
                continue
            visited[i] = 1
            out.append(nums[i])
            self.DFS(nums, level+1, visited, out, res)
            out.pop()  ## del out[-1] out.pop(-1)
            visited[i] = 0

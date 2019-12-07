class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        out = []
        n = len(nums)
        if n==0 :
            return res
        
        visited = [ 0 for i in range(n)]
        nums= sorted(nums)
        self.DFS(nums,0,visited,out,res)
        return res
    def DFS(self,nums:List[int],level:int,visited:List[int],out:List[int],res:List[List[int]]):
        n = len(nums)
        if level == n:
            res.append(out[:])
            return
        for i in range (0,n):
            if visited[i] ==1:
                continue
            if i>=1 and nums[i]==nums[i-1] and visited[i-1]==0:
                continue
            visited[i]=1
            out.append(nums[i])
            self.DFS(nums,level+1,visited,out,res)
            out.pop()
            visited[i]=0

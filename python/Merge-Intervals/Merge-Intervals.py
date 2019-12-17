##Python Solution 1:

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        merged = []
        for interval in intervals:
            if not merged or merged[-1][-1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][-1] = max(merged[-1][-1], interval[-1]) #如果能连接上我们就连
        
        return merged

      
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n=len(intervals)
        if n==0:
            return []
        intervals = sorted(intervals,key=lambda x:x[0])
        res = [intervals[0]]
        for i in range(1,n):
            if res[-1][1]<intervals[i][0]:
                res.append(intervals[i])
            else:
                res[-1][1]=max(res[-1][1],intervals[i][1])
        return res
      
      
## Python Solution 2:
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n=len(intervals)
        if n==0:
            return []
        res =[]
        starts=[]
        ends=[]
        for i in range(n):
            starts.append(intervals[i][0])
            ends.append(intervals[i][1])
        starts = sorted(starts)
        ends = sorted(ends)
        i=0
        j=0
        while i<n:
            if i==n-1 or starts[i+1]>ends[i]:
                res.append([starts[j],ends[i]])
                j=i+1
            i+=1
        return res

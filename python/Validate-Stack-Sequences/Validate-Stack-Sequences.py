class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        n = len(pushed)
        m = len(popped)
        if n!=m:
            return False
        s = []
        index = 0
        for i in range(n):
            s.append(pushed[i])
            while len(s)>0 and s[-1]==popped[index]:
                s.pop()
                index+=1
        return len(s)==0

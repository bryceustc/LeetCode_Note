

##### Solution 1:
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        n = len(strs)
        if n==0:
            return res
        dic = {}
        for s in strs:
            t = s
            t = "".join(sorted(t))
            if t not in dic:
                dic[t] = len(res)
                res.append([])
            res[dic[t]].append(s)
        return res
 



### Solution 2:
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        dic = {}
        m ={}
        n = len(strs)
        if n==0: 
            return res
        for s in strs:
            t = s
            t = "".join(sorted(t))
            if t not in dic:
                dic[t] = [s]
            else:
                dic[t].append(s)
        res = list(dic.values())
        return res

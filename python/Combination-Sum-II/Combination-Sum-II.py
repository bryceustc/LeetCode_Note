#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-12-1
# Author: Bryce

from typing import List
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        out = []
        candidates = sorted(candidates)
        self.DFS(candidates,target,0,out,res)
        return res
    def DFS(self,candidates: List[int], target:int, start: int, out: List[int], res: List[List[int]]):
        if target < 0:
            return
        if target == 0:
            res.append(out[:])
            return
        n = len(candidates)
        for i in range(start,n):
            if candidates[i] == candidates[i-1] and i > start:
                continue
            out.append(candidates[i])
            self.DFS(candidates,target-candidates[i],i+1,out,res)
            del out[-1]
            
if __name__ == " __main__ ":
    candidates = [10,1,2,7,6,1,5]
    target = 8
    print (Solution().combinationSum2(candidates, target))

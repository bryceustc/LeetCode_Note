#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-30
# Author: Bryce


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        out = []
        self.DFS(candidates, target, 0, out, res)
        return res
    def DFS(self, candidates: List[int], target: int, start: int, out: List[int], res: List[List[int]]):
        if target < 0: return
        if target == 0:
            res.append(out[:])
            return
        n = len(candidates)
        for i in range (start,n):
            out.append(candidates[i])
            self.DFS(candidates,target-candidates[i],i,out,res)
            out.pop()  ## out.pop(-1) or del out[-1]

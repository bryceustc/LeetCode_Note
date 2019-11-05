#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-06
# Author: Bryce

# Python Solution 1:
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = ""
        for tmp in zip(*strs):              #zip ()打包 加星号是解压操作
            tmp_set = set(tmp)              #set() 函数创建一个无序不重复元素集，可进行关系测试，删除重复数据，还可以计算交集、差集、并集等。
            if len(tmp_set) == 1:           
                res += tmp[0]
            else:
                break
        return res
      
    # Python Solution 2:
    class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        res = strs[0]
        i = 1
        while i < len(strs):
            while strs[i].find(res) != 0:
                res = res[0:len(res)-1]
            i += 1
        return res

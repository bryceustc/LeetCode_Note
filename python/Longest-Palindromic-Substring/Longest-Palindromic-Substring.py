#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Author: Bryce


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        l=list(s)
        length = len(l)
        if length == 0:
            return ""
        if length == 1:
            return s
        temp=[]
        result = []
        i = 0
        ii = 0
        j = 1
        flag = True
        while ii < length:
            i = ii - 1
            j = ii + 1
            while j < length and l[ii] == l[j]:
                j = j + 1
                temp = l[ii:j]
            while (i>=0 and j<=length-1 and l[i] == l[j]):
                temp = l[i:j+1]
                i = i - 1
                j = j + 1
            if len(temp) > len(result):
                result = temp
            ii = ii + 1            
        if len(result) == 0:
            return l[0]
        return "".join(result)





class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 如果字符串长度小于2或者s等于它的倒序，则直接返回s
        if len(s) < 2 or s == s[::-1]:
            return s
        n = len(s)
        # 定义起始索引和最大回文串长度，odd奇，even偶
        start, maxlen = 0, 1
        # 因为i=0的话必然是不可能会有超过maxlen情况出现，所以直接从1开始
        for i in range(1, n):
            # 取i及i前面的maxlen+2个字符
            odd = s[i - maxlen - 1:i + 1]  # len(odd)=maxlen+2
            # 取i及i前面的maxlen+1个字符
            even = s[i - maxlen:i + 1]  # len(even)=maxlen+1
            if i - maxlen - 1 >= 0 and odd == odd[::-1]:
                start = i - maxlen - 1
                maxlen += 2
                continue
            if i - maxlen >= 0 and even == even[::-1]:
                start = i - maxlen
                maxlen += 1
        return s[start:start + maxlen]

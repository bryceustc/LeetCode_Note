#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-10-30
# Author: bryce

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        res = 0;
        r = 0
        i = 0;
        flag = 1;
        
        if len(str) == 0:
            return 0
        while (i < len(str) and (str[i]==' ' or str[i]=='/t')):
            i+=1
        if (i > len(str)):
            return 0
        if (i < len(str) and str[i]=='-'):
            flag = -1
            i+=1
        if (i < len(str) and str[i]=='+'):
            if(flag == -1):
                return 0
            i+=1
        while (i < len(str) and str[i] >= '0' and str[i] <= '9'):
            r = int (ord(str[i]) - ord('0'))
            if res > (pow(2,31) - 1)/10 or (res == (pow(2,31) - 1)/10 and r > 7 ):
                if flag > 0:
                    res_max = pow(2,31) - 1
                    return res_max
                else:
                    res_min = - pow(2,31)
                    return res_min
            res = res * 10 + r
            i+=1
        res *=flag
        return res

#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-12-5
# Author: Bryce

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res =""
        n1 = len(num1)
        n2 = len(num2)
        i = n1-1
        j = n2-1
        carry = 0
        while i >=0 or j >=0:
            if i < 0:
                temp = ord(num2[j]) - ord('0') + carry
            if j < 0:
                temp = ord(num1[i]) - ord('0') + carry
            if i>=0 and j>=0:
                temp = (ord(num1[i]) -ord('0')) + (ord(num2[j]) - ord('0')) + carry
            carry = temp // 10
            temp = temp%10
            res += str(temp)
            i=i-1
            j=j-1
        if carry>0:
            res+=str(carry)
        return res[::-1]

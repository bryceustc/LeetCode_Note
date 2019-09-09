#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 8/12/19
# Author: zhang dingyuan

class Solution:
    def twoSum ( self , nums, target ):
    dic={ };
    for index, num in enumerate ( nums ):
        if num in dic :
            return  [ dic [ num] ], index ]
        dic [ target - num ]= index
if __name__ == " __main__ ":
    nums = [ 2 , 7 , 11 , 15 ]
    target = 9
    print ( Solution( ).twoSum ( nums, target ) )

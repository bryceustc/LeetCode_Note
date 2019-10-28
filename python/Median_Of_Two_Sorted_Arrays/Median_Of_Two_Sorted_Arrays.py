#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Author: Bryce

class Solution(object):
   def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n = len(nums1)
        m = len(nums2)
        left = (m + n + 1)/2
        right = (m+n+2)/2
        left = int (left)
        right = int (right)
        res_l = self.find_Kth_num(nums1, nums2, left)
        res_r = self.find_Kth_num(nums1, nums2, right)
        res = (res_l + res_r)/2.0
        return res
 
    def find_Kth_num(self, nums1, nums2, k):
        if len(nums1) == 0:
            return nums2[int(k - 1)]
        if len(nums2) == 0:
            return nums1[int(k - 1)]
        if k == 1:
            return min(nums1[0], nums2[0])
        
        a = nums1[int(k / 2) - 1] if len(nums1) >= k / 2 else None
        b = nums2[int(k / 2) - 1] if len(nums2) >= k / 2 else None
        if b is None or (a is not None and a < b):
            return self.find_Kth_num(nums1[int(k / 2):], nums2, int(k - k // 2))
        return self.find_Kth_num(nums1, nums2[int(k / 2):], int(k - k // 2))


if __name__ == '__main__':
    s = Solution()
    print(s.findMedianSortedArrays([1,2], [3,4]))

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
        res_l = self.find_Kth_num(nums1, 0 , n-1, nums2, 0, m-1, left)
        res_r = self.find_Kth_num(nums1, 0, n-1, nums2, 0, m-1, right)
        res = (res_l + res_r)/2
        return res
    
    def find_Kth_num(self, nums1, start1, end1, nums2, start2, end2, k):
        len1 = start1 - end1 + 1
        len2 = start2 - end2 + 1
        if(len1 < len2):
            return (self.find_Kth_num(nums2, start2, end2, nums1, start1, end1, k))
        if(len1 == 0):
            return(nums2[(start2+k-1)])
        if(k == 1):
            return(min(nums1[int(start1)],nums2[int(start2)]))
        i = start1 + min(len1,k/2) - 1
        j = start2 + min(len2,k/2) - 1
        
        if (nums1[i] > nums2[j]):
            return (self.find_Kth_num(nums1, start1, end1, nums2, j+1, end2, k-(j-start2+1)))
        else:
            return (self.find_Kth_num(nums1, i+1, end1, nums2, start2, end2, k-(i-start1+1)))
if __name__ == '__main__'
    s = Solution()
    print(s.findMedianSortedArrays([1,2,3,4,5,6], [2,3,4,5]))

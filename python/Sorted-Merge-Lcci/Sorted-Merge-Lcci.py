class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1
        j = n-1
        index = m+n-1
        while i>=0 and j>=0:
            if A[i] >= B[j]:
                A[index] = A[i]
                index-=1
                i-=1
            else:
                A[index] = B[j]
                index -=1
                j-=1
        # 比较完B还有剩下的，全填到A前面即可
        A[:j+1] = B[:j+1]

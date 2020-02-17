## Solution 1:
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        res = True
        if root:
            res = self.helper(root.left, root.right)
        return res
    
    def helper(self,A,B):
        if A is None and B is None:
            return True
        if A is None or B is None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left,B.right) and self.helper(A.right,B.left)
### Solution 2:
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        q = []
        q.append(root.left)
        q.append(root.right)
        while len(q)!=0:
            A = q.pop(0)
            B = q.pop(0)
            if A == None and B == None:
                continue
            if A == None or B == None:
                return False
            if A.val != B.val:
                return False
            q.append(A.left)
            q.append(B.right)
            q.append(A.right)
            q.append(B.left)
        return True 

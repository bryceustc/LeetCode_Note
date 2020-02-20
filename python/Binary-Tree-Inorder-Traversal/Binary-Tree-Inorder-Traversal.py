class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        self.helper(root,res)
        return res
    def helper(self,root,res):
        if root is None:
            return
        self.helper(root.left,res)
        res.append(root.val)
        self.helper(root.right,res)

        
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        s = []
        p = root
        while p or s:
            while p!=None:
                s.append(p)
                p = p.left
            p = s.pop()
            res.append(p.val)
            p = p.right
        return res

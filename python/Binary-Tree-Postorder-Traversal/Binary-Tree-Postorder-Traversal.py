class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        self.helper(root,res)
        return res
    def helper(self,root,res):
        if root is None:
            return
        self.helper(root.left,res)
        self.helper(root.right,res)
        res.append(root.val)

        
        
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        s = []
        s.append(root)
        while s:
            node = s.pop()
            if node.left:
                s.append(node.left)
            if node.right:
                s.append(node.right)
            res.append(node.val)
        return res[::-1]

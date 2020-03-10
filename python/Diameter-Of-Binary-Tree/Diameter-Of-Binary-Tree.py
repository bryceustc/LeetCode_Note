class Solution:
    def __init__(self):
        self.res = 0
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.res
    
    def dfs(self, root):
        if root is None:
            return 0
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        self.res = max(left+right, self.res)
        return max(left, right) + 1

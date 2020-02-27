class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        if abs(left-right)>1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    def TreeDepth(self, root):
        if root is None:
            return 0
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        return max(left, right) + 1
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.helper(root)[0]
    def helper(self, root):
        if root is None:
            return True, 0
        leftIsBalanced, left = self.helper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced,right = self.helper(root.right)
        if not rightIsBalanced:
            return False, 0
        return (abs(left - right)<=1), max(left, right) +1

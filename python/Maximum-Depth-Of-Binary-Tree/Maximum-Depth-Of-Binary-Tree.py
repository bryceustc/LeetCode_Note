class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left, right)+1
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        depth = 0
        if root is None:
            return depth
        q = []
        q.append(root)
        while q:
            count = len(q)
            while count >0:
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                count -=1
            depth+=1
        return depth

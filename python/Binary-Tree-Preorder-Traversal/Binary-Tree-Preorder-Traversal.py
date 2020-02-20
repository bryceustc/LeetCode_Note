## Solution 1:
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        self.helper(root, res)
        return res
    def helper(self, root, res):
        if root is None:
            return
        res.append(root.val)
        self.helper(root.left, res)
        self.helper(root.right, res)
## Solution 2：

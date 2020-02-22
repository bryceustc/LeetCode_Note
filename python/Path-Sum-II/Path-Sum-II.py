class Solution:
    def __init__(self):
        self.res = []
        self.path = []
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root is None:
            return self.res
        self.dfs(root, self.path, sum)
        return self.res
    def dfs(self, root, path, sum):
        if root is None:
            return
        self.path.append(root.val)
        if sum == root.val and (root.left is None and root.right is None):
            self.res.append(self.path[:])
        self.dfs(root.left, self.path, sum - root.val)
        self.dfs(root.right, self.path, sum - root.val)
        self.path.pop()

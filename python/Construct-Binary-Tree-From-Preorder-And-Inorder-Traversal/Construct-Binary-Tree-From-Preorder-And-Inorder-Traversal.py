# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        n = len(preorder)
        root = preorder[0]
        t = TreeNode(root)
        root_index = 0
        for i in range(n):
            if inorder[i]==root:
                root_index = i
                break
        left_pre = []
        left_in = []
        right_pre = []
        right_in = []
        for i in range (root_index):
            left_pre.append(preorder[i+1])
            left_in.append(inorder[i])
        for i in range(root_index+1,n):
            right_pre.append(preorder[i])
            right_in.append(inorder[i])
        t.left = self.buildTree(left_pre,left_in)
        t.right = self.buildTree(right_pre, right_in)
        return t
      
      
## Solution 2:
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        root = TreeNode(preorder.pop(0))
        index = inorder.index(root.val)
        root.left = self.buildTree(preorder, inorder[:index])
        root.right = self.buildTree(preorder, inorder[index+1:])
        return root

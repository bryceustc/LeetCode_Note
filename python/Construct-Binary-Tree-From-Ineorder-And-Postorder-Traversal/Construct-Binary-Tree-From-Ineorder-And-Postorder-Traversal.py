### Solution 1:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        n = len(inorder)
        root = postorder[-1]
        t = TreeNode(root)
        for i in range(n):
            if inorder[i]==root:
                root_index = i
                break
        left_in = []
        left_post = []
        right_in = []
        right_post = []
        for i in range(root_index):
            left_in.append(inorder[i])
            left_post.append(postorder[i])
        for i in range(root_index+1,n):
            right_in.append(inorder[i])
        for i in range(root_index,n-1):
            right_post.append(postorder[i])
        t.left = self.buildTree(left_in, left_post)
        t.right = self.buildTree(right_in, right_post)
        return t
### Solution 2:
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        root = TreeNode(postorder[-1])
        index = inorder.index(root.val)
        root.left = self.buildTree(inorder[:index],postorder[:index])
        root.right = self.buildTree(inorder[index+1:], postorder[index:-1])
        return root

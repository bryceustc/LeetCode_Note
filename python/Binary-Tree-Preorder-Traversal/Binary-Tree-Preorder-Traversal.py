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
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        s = []
        s.append(root)
        ## s = [root,] 
        #,理解 这个是方便多行定义的时候复制的,否则容易在添加元素的过程中缺少逗号出现语法错误.
        # 具体可以查python data structure trailing comma这个关键词. 
        # 对于tuple的定义就有差别了,因为(1)这个东西有二意性,所以tuple声明单元素的时候必须加逗号,也就是(1,)
        while s:
            node = s.pop()
            res.append(node.val)
            if node.right:
                s.append(node.right)
            if node.left:
                s.append(node.left)
        return res

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        s = []
        p = root
        while s or p:
            while p:
                s.append(p)
                res.append(p.val)
                p=p.left
            p = s.pop()
            p = p.right
        return res

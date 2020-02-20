class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = collections.deque()
        q.append(root)
        zigzag = True
        while q:
            n = len(q)
            out = []
            node = None
            while n>0:
                if zigzag:
                    node = q.popleft()
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    node = q.pop()
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
                out.append(node.val)
                n-=1
            res.append(out[:])
            zigzag= not zigzag
        return res

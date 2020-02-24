class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root  is None:
            return None
        pre = None
        pre = self.helper(root, pre)
        head = pre
        while head and head.left:
            head = head.left
        pre.right = head
        head.left = pre
        return head
    def helper(self, cur,  pre):
        if cur == None:
            return pre
        pre = self.helper(cur.left, pre)
        cur.left = pre
        if pre:
            pre.right = cur
        pre = cur
        return self.helper(cur.right, pre)

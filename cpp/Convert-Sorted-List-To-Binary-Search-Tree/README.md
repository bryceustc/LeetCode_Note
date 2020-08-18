# 题目描述:  将有序链表转换为二叉搜索树

将一个按照升序排列的有序链表，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。


**示例 :**
```
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

# 解题思路:
用两个指针，一块一慢，快的每次走两步，慢的每次走一步，这样当快指针遍历结束时，慢指针指向的也就是链表的中间位置。这时候把中间位置的结点的值作为二叉搜索树当前结点的值
# 时间复杂度：
O(n) 
# 空间复杂度
O(logn) 递归需要O(logn)栈空间
  
# 代码
比较笨的一种方法是转成数组来做
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode *p = head;
        while ( p) {
            nums.push_back(p->val);
            p = p->next;
        }
        int n = nums.size();
        return helper(nums, 0, n - 1);
    }
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);
        return root;
    }
};
```

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==nullptr) return nullptr;
        if (head->next== nullptr) return new TreeNode(head->val);
        ListNode* p = head;
        ListNode* q = head;
        ListNode* pre = head;
        //找到链表的中点p
        while (q && q->next) {
            pre = p;
            p = p->next;
            q = q->next->next;
        }
        // 分为前后两个半段
        pre->next = nullptr;
        TreeNode* root = new TreeNode(p->val);
        p = p->next;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(p);
        return root;
    }
};
```

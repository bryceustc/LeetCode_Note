# 题目描述:  将有序数组转换为二叉搜索树

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

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
1. 将合并 k个链表的问题转化成合并 2 个链表 k-1次

2. 归并排序的思想，分治。

- 将 k个链表配对并将同一对中的链表合并
- 第一轮合并以后， k 个链表被合并成了 k/2个链表，平均长度为 2N/k ，然后是 k/4个链表， k/8个链表等等
- 重复这一过程，直到我们得到了最终的有序链表

因此，我们在每一次配对合并的过程中都会遍历几乎全部N个节点，并重复这一过程
# 时间复杂度：
O(n) 
# 空间复杂度
O(logn) 递归需要O(logn)栈空间
  
# 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n - 1);
    }

    TreeNode* helper(vector<int> &nums, int l , int r) {
        if (l > r) return NULL;
        int mid = l  + (r - l ) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);
        return root;
    }
};
```

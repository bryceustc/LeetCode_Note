# 题目描述:  打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。


**示例 :**
```
输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
```

# 解题思路:
   递归

  树形动态规划：
  
  每个节点可选择偷或者不偷两种状态，根据题目意思，相连节点不能一起偷

   - 当前节点选择偷时，那么两个孩子节点就不能选择偷了
   - 当前节点选择不偷时，两个孩子节点只需要拿最多的钱出来就行(两个孩子节点偷不偷没关系)
   
我们使用一个大小为2的数组来表示vector<int> res(2)  0代表不偷，1代表偷

任何一个节点能偷到的最大钱的状态可以定义为

   - 当前节点选择不偷: 当前节点能偷到的最大钱数 = 左孩子能偷到的钱 + 右孩子能偷到的钱
   - 当前节点选择偷: 当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
公式如下
```
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
```
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码
### 递归超时
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
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int res1 = root->val;
        if (root->left)
        {
            res1+= (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right)
        {
            res1+=(rob(root->right->left) + rob(root->right->right));
        }
        int res2  = 0;
        res2 = rob(root->left) + rob(root->right);
        //  4个孙子偷的钱 + 爷爷的钱 VS 两个儿子偷的钱 哪个组合钱多，就当做当前节点能偷的最大钱数
        return max(res1, res2);
    }
};
```
###  递归优化 
```c++
/**
爷爷在计算自己能偷多少钱的时候，同时计算了4个孙子能偷多少钱，
也计算了2个儿子能偷多少钱。这样在儿子当爷爷时，就会产生重复计算一遍孙子节点。所以上述情况会超时
 */
class Solution {
public:
    int rob(TreeNode* root) {
        // 使用哈希表进行缓存数据
        unordered_map<TreeNode*, int> m;
        return helper(root, m);
    }
    int helper(TreeNode* root, unordered_map<TreeNode*, int> &m) // 注意加&
    {
        if (root==NULL) return 0;
        cout << m.count(root) << endl;
        if (m.count(root)) 
            return m[root];
        int res1 = root->val;
        if (root->left)
        {
            res1+= (helper(root->left->left, m) + helper(root->left->right, m));
        }
        if (root->right)
        {
            res1+= (helper(root->right->left, m) + helper(root->right->right, m));
        }
        int res2 = helper(root->left, m) + helper(root->right, m);
        int res = max(res1, res2);
        m[root] = res;
        return res;
    }
};
```
### 树形dp法
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
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        // res
        return max(res[0], res[1]);
    }
    vector<int> helper (TreeNode* root)
    {
        vector<int> res (2,0);
        if (root==NULL) return res;
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};
```

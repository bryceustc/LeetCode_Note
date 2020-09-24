###题目描述 寻找二叉搜索树的众数

暴力方法：
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
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return res;
        dfs(root);
        int cnt = 1;
        int count = 0;
        unordered_map<int, int> m;
        int a = nums[0];
        m[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == a) {
                cnt++;
            }
            else {
                a = nums[i];
                count = max(count, cnt);
                cnt = 1;
            }
            m[nums[i]]++;
        }
        count = max(count, cnt);
        for (auto &p : m) {
            if (p.second == count) res.push_back(p.first); 
        }
        return res;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
private:
    vector<int> nums;
    vector<int> res;
};
```

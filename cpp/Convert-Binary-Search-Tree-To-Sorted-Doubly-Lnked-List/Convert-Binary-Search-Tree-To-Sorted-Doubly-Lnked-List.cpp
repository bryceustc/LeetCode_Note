class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root==NULL)
            return NULL;
        Node* pre = NULL;
        helper(root, pre);
        Node* head =pre;
        while(head && head->left)
        {
            head = head->left;
        }
        pre -> right = head;
        head->left = pre;
        return head;
    }
    void helper(Node* cur, Node* &pre)
    {
        if (cur==NULL)
            return;
        helper(cur->left, pre);
        cur->left = pre;
        if (pre!=NULL)
            pre->right = cur;
        pre = cur;
        helper(cur->right, pre);
    }
};

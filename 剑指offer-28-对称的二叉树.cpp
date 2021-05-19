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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : func(root->left, root->right);
    }
    bool func(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;
        return func(left->left, right->right) && func(left->right, right->left);
    }
};
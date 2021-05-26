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
    vector<vector<int>> ans;
    void func(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (ans.size() < depth) {
            vector<int> vt = {root->val};
            ans.push_back(vt);
        }
        else ans[depth - 1].push_back(root->val);
        func(root->left, depth + 1);
        func(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        func(root, 1);
        return ans;
    }
};
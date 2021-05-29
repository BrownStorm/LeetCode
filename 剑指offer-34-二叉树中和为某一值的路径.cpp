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
    vector<int> path;
    vector<vector<int>> ans;
    void func(TreeNode* root, int target) {
        if (root == nullptr) return;
        target -= root->val;
        path.push_back(root->val);
        if (!target && !root->left && !root->right) ans.push_back(path);
        func(root->left, target);
        func(root->right, target);
        path.erase(--path.end());
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        func(root, target);
        return ans;
    }
};
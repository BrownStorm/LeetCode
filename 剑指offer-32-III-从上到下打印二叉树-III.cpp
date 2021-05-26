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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        stack<TreeNode*> s1, s2;
        TreeNode* node;
        vector<int> v;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                node = s1.top();
                s1.pop();
                v.push_back(node->val);
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }
            if (!v.empty()) ans.push_back(v);
            v.clear();
            while (!s2.empty()) {
                node = s2.top();
                s2.pop();
                v.push_back(node->val);
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }
            if (!v.empty()) ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};
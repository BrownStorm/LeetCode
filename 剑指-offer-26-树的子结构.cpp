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
    // 包含：以A为根的数是否包含B（必须从A开始）
    bool isContain(TreeNode* A, TreeNode* B){
        if(B == NULL)
            return true;
        if(A == NULL || A->val != B->val)
            return false;
        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A == NULL)
            return false;
        // 遍历A中每个节点，A树中任一节点包含B就能返回true
        return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
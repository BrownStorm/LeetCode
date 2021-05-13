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
    // ��������AΪ�������Ƿ����B�������A��ʼ��
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
        // ����A��ÿ���ڵ㣬A������һ�ڵ����B���ܷ���true
        return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
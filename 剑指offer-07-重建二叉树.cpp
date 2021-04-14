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
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(const vector<int> preorder, const vector<int> inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        cout << "preorder_left:\t\t" << preorder_left << endl;
        cout << "preorder_right:\t" << preorder_right << endl;
        cout << "inorder_left:\t\t" << inorder_left << endl;
        cout << "inorder_right:\t\t" << inorder_right << endl;
        cout << "--------------------------------------------------------------------" <<endl;
        // 结束条件不可以有等号
        // 因为当子树只有一个节点时，preorder_left==preorder_right，size_left=0。
        // 在下一次递归时preorder_left+=1，而preorder_right=preorder_left+size_left。这时preorder_left>preorder_right
        if (preorder_left > preorder_right) return nullptr;
        int inorder_root = index[preorder[preorder_left]];
        // 有size才可以从先序遍历序列中得到左右子树
        int size_left = inorder_root - inorder_left;
        int size_right = inorder_right - inorder_root;
        TreeNode *root = new TreeNode(preorder[preorder_left]);
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left, inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_right - size_right + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 建立哈希映射，以便快速从中序遍历中找到根节点
        for (int i = 0; i < preorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
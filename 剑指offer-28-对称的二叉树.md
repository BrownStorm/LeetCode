# 对称二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

        1
       / \
      2   2
     / \ / \
    3  4 4  3 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

        1
       / \
      2   2
       \   \
       3    3


## 思考

如果一棵二叉树是对称的，那么对于树中任意两个对称节点`left`、`right`一定满足：

1. `left->val == right->val`：对称的节点值相等
2. `left->left->val == right->right->val`
3. `left->right->val == right->left->val`：对称节点子节点的相应对称节点值相等

算法流程：

`isSymmetric(TreeNode *root)`：

- 特例处理：若根节点为空，则返回`true`
- 返回值：`func(root->left, root->right)`

`func(TreeNode *left, TreeNode *right)`：

结束条件：

- 当两节点都为空则对称，返回`true`
- 若两节点有一为空，另一不为空，则返回`false`
- 若两节点都不为空，且值不相等，则返回`false`

递推工作：

- 判断`left->left`与`left->right`是否对称
- 判断`left->right`与`right->left`是否对称

## 复杂度

- 时间复杂度$O(N)$：其中N为节点数
- 空间复杂度$O(N)$：最差情况，二叉树退化成链表，栈空间大小为$O(N)$
# 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。



## 思路

若树B是树A的子结构，则子结构的根节点可能为树A的任一节点。因此判断树B事都是树A的子结构需要：

1. 先序遍历树A中的每个节点（`isSubStructure(A, B)`）
2. 判断树A中以Ai为根节点的子树是否包含树B(`isContain(A, B)`)



函数`isContain(TreeNode *A, TreeNode *B)`：

终止条件：

- 当B为空，则说明B的所有节点都已完成匹配，因此返回`true`
- 当A为空或当前A的值与B的值不同，则说明匹配失败，返回`false`

返回值：

- 判断A和B的左节点是否相等（`isContain(A->left, B)`）
- 判断A和B的右节点是否相等（`isContain(A->right, B)`）



函数`isSubStruction(TreeNode *A, TreeNode *B)`：

特例处理：当树A或树B为空，则返回`false`

返回值：若树B是树A的子结构，则必须满足以下三种情况之一：

1. 以节点A为根节点的子树包含B（`isContain(A, B)`）
2. 以节点A的左节点为根节点的子树包含B（`isContain(A->left, B)`）
3. 以节点A的右节点为根节点的子树包含B（`isContain(A->right, B)`）

## 复杂度

- 时间复杂度：假设M、N分别为树A与树B的节点数；先序遍历树A为$O(M)$，每次调用`isContain`为$O(N)$；依次对树A的每个节点调用`isContain`，则时间复杂度为$O(MN)$
- 空间复杂度：$O(M)$。当树A与树B都退化为链表，递归调用深度达到最大。当$M<=N$时，遍历树A与递归判断的总递归深度为M；当$M>N$时，最差情况为遍历至树A的叶子节点。此时总递归深度为M


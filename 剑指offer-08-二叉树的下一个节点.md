# 二叉树的下一个节点

题目：给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？树中的节点除了有两个分别指向左右孩子节点的指针，还有一个指向父节点的指针。

有三种情况：

1. 如果这个节点有右子树。那么它的下一个节点就是它的右子树中的最左节点。
2. 如果这个节点没有右孩子，且他是的父节点的左孩子。那么它的下一个节点就是它的父节点。
3. 如果这个节点没有右孩子，且他不是父节点的左孩子。那么我们需要沿着父节点一直向上遍历，直到找到一个它是父节点的左孩子的节点。如果这个节点存在，那么它的父节点就是我们要找的节点。如果不存在，那么下一个节点就是`nullptr`（根节点的父节点）。

在书写代码时，其中第2、3种情况可以合并一起书写。
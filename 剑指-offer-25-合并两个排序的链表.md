# 合并两个有序链表


输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

**示例1：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```



## 思考

使用两个指针，分别指向两个链表中的节点，依次比较即可。

因为需要返回一个有序链表的头结点，所以需要先决定头结点取自哪个链表，而后将那个链表向后移动一位。

## 复杂度

- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$



## 其他方法

可以使用递归：

- 如果`l1->val < l2->val`将`l1->next`赋予`func(l1->next, l2)`
- 反之，将`l2->next`赋予`func(l1, l2->next)`
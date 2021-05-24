# 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例：

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```



## 思考

只使用一个栈无法解决问题，因为需要时间复杂度为$O(1)$，每次寻找最小元素都得遍历整个栈，或者push时让栈有序，时间复杂度都是$O(n)$。

如果使用一个栈加上一个int型变量用来保存当前栈的最小值。这显然也不行。因为如果将其pop弹出栈，栈之后的最小值又是什么？

之后我们想到可以使用双栈。一个栈s1用于正常的pop与push数据，另一个栈s2用来保存当前位置的最小值。将s2缩小可以变成`if(x <= s2.top())`则push。这时min()只需返回s2.top()



`push(x)`：

s1正常压栈

`if(x <= s2.top()`则入栈s2



`pop()`：

s1正常出栈

`if(s1.top() == s2.top())`s2栈顶元素出栈



`min()`和`top()`：注意栈是否为空即可



## 复杂度

- 时间复杂度：$O(1)$
- 空间复杂度：$O(N)$。最差情况为N个元素递减入栈，则此时辅助栈s2需要存储N个元素
BinTreeNode* GetNext(BinTreeNode pNode){
	if (pNode == nullptr) return nullptr;
	BinTreeNode* pNext = nullptr;
	if (pNode->rChild) {
		pNext = pNode->rChild;
		// 循环直至找到pNode的右子树的最左下角的节点
		while(pCurrent->lChild) pNext = pNext->lChild;
	} else if (pNode->pParent) {
		BinTreeNode* pCurrent = pNode->pParent;
		// 循环直至找到pCurrent是其父节点的左孩子时，如果不存在，将在全树根节点处停止循环
		while(pCurrent->pParent && pCurrent != pCurrent->lChild) pCurrent = pCurrent->pParent;
		pNext = pCurrent->pParent;
	}
	return pNext;
}
/*
 * 删除链表的节点
 *
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 *
 * */


/*思路一：找到下一个节点为待删除节点，调整当前节点指向*/
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v=0): val(v), next(NULL){}
};


class Solution{
public:
	ListNode* deleteNode(ListNode* head, int val){
		if(head->val == val)
			return head->next;
		ListNode* pNode = head;
		while(pNode->next && pNode->next->val != val)
			pNode = pNode->next;
		if(!pNode->next)
			return NULL;
		ListNode* pDeleted = pNode->next;
		delete pDeleted;
		pNode->next = pNode->next->next;
		return head;
	}

};


/*思路二， linus 指针解法*/
struct ListNode{
	int val;
	ListNode* next;
};

class Solution1{
public:
	struct ListNode deleteNode(struct ListNode* head, int val){
		struct ListNode** indirect = &head;
		struct ListNode* tmp;
		for(; *indirect; indirect = &((*indirect)->next)){
			if((*indirect->val) == val){
				tmp = *indirect;
				*indirect = (*indirect)->next;
				free(tmp);
				break;
			}
		}
		return head;
	}
};


/*删除排序链表中的重复节点*/
void deleteDuplicateNode(ListNode** pHead){
	if(!pHead || !*pHead)
		return;
	ListNode* pNode = *pHead;
	ListNode* pPreNode = NULL;
	while(pNode){
		ListNode* pNext = pNode->next;
		bool needDelete = false;
		if(pNext && pNext->val == pNode->val)
			needDelete = true;
		if(!needDelete){
			pPreNode = pNode;
			pNode = pNext;
		}
		else{
			int val = pNode->val;
			ListNode* pDeleted = pNode;
			// 所有==val的节点全部删除
			while(pDeleted!=NULL && pDeleted->val == val){
				pNext = pDeleted->next;
				delete pDeleted;
				pDeleted = pNext;
			}
			if(!pPreNode)
				*pHead = pNext;
			else
				pPreNode->next = pNext;
			pNode = pNext;
		}
	}
}

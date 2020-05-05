/*
 * 反转链表
 *
 * 用三个指针反转，pre , cur, next
 * */

class Solution{
public:
	ListNode* reverseList(ListNode* pHead){
		ListNode* cur = pHead, pre = NULL, next = NULL;
		while(cur){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


/*
 *
 * 合并有序链表
 *
 * */

class Solution{
public:
	ListNode* mergeList(ListNode* l1, ListNode* l2){
		ListNode* pHead = new ListNode(0);
		ListNode8 pNode = pHead;
		while(l1 && l2){
			if(l1->val > l2.val){
				pNode->next = l1;
				l1 = l1->next;
			}
			else{
				pNode->next = l2;
				l2 = l2->next;
			}
			pNode = pNode->next;
		}
		pNode->next = l1 ? l1 : l2;
		return pHead->next;
	}
};

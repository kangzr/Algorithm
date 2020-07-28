/*
 * 复杂链表的复制
 *
 * 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，
 * 每个节点除了有一个 next 指针指向下一个节点，
 * 还有一个 random 指针指向链表中的任意节点或者 null。
 *
 * */

struct Node{
	int val;
	Node* next;
	Node* random;
	Node(int v): val(v), next(NULL), random(NULL){}
};


/*思路一：
 *
 * 用一个map将原节点跟新复制的节点一一映射
 * 再遍历设置next和random
 *
 * 时间复杂度O(n) 空间复杂度O(n)
 *
 * */

class Solution{
	Node* CloneComplexList(Node* head){
		if(!head) return head;
		unordered_map<Node*, Node*> mp;
		Node* pNode = head;
		while(pNode){
			mp[pNode] = new Node(pNode->val);
			pNode = pNode->next;
		}
		pNode = head;
		while(pNode){
			if(pNode->next)
				mp[pNode]->next = mp[pNode->next];
			if(pNode->random)
				mp[pNode]->random = mp[pNode->random]
		}
		return mp[head];
	}

};


/* 思路二 分三步
 * 1. 复制节点
 * 2. 连接ramdon节点
 * 3. 拆分链表
 *
 * 时间复杂度 O(n) 空间复杂度O(1)
 * */
class Solution{
public:
	Node* CloneComplextList(Node* head){
		if(!head) return head;
		copyNodes(head);
		connectRandomNodes(head);
		return splitList(head);
	}

	void copyNodes(Node* head){
		Node* pNode = head;
		while(pNode){
			Node* pClone = new Node(pNode->val);
			pClone->next = pNode->next;
			pNode->next = pClone;
			pNode = pClone->next;
		}
	}

	void connectRandomNodes(Node* head){
		Node* pNode = head;
		while(pNode){
			Node* pClone = pNode->next;
			if(pNode->random) pClone->random = pNode->random->next;
			pNode = pClone->next;
		}
	}

	Node* splitList(Node* head){
		Node* pCloneNode = NULL;
		Node* pCloneHead = NULL;
		Node* pNode = head;
		if(pNode->next){
			pCloneHead = pCloneNode = pNode->next;
			pNode->next = pCloneHead->next;
			pNode = pNode->next;
		}

		while(pNode){
			pCloneNode->next = pNode->next;
			pCloneNode = pCloneNode->next;
			pNode->next = pCloneNode->Next;
			pNode = pNode->next;
		}
		return pCloneHead;
	}
};

/*
 * 链表环入口
 *
 * 思路(快慢指针)
 * 1. pSlow每次走一步(x)，pFast每次都两步(2x), 如果有环，则必相遇，
 *   且相遇时，2x = x + n * m, 其中n为环节点数，m为pFast比pSlow多走的环圈数
 *   此时，
 * 2. pSlow重新指向起点，两者再以每次一步走，相遇点即为环入口
 *
 * 证明：
 * 2x = x + n * m
 * x = a + e   // a 为起点到入口距离，e为入环后pSlow走过的距离
 * a + e = n * m
 * a = n * m - e = n*(m - 1) + n - e // 其中n - e即为第一次相遇时距离入口还需要走的距离
 *
 * 因此 pFast走m-1圈+ n-e即到了环入口，且再此遇到pSlow
 * */


class Solution{
public:
	ListNode* entryNode(ListNode* pHead){
		ListNode* pSlow = pHead, pFast = pHead;
		while(pFast){
			pFast = pFast->next;
			pSlow = pSlow->next;
			if(pFast) pFast = pFast->next;
		}
		if(!pFast)
			return NULL;
		pSlow = pHead;
		while(pSlow != pFast)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
		}
		return pFast;
	}

};

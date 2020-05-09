/*
 * 二叉搜索树与双向链表
 *
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
 * 要求不能创建任何新的节点，只能调整树中节点指针的指向。
 *
 * 将二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针
 * 对于双向循环链表，第一个节点的前驱是最后一个节点，
 * 最后一个节点的后继是第一个节点。
 *
 * */


/*思路一：
 *
 * 1. 中序遍历得到一个有序数组，即为链表顺序
 * 2. 遍历链表连接左右节点即可
 *
 * 时间复杂度O(n) 空间复杂度O(n)
 *
 * */

class Solution1{
public:
	vector<Node*> vec;
	void helper(Node* root){
		if(!root) return;
		helper(root->left);
		vec.emplace_back(root);
		helper(root->right);
	}

	Node* convertTreeToList(Node* root){
		if(!root) return NULL;
		helper(root);
		int len = vec.size() - 1;
		for(int i = 0; i < len; i++){
			vec[i]->left = vec[i+1];
			vec[i+1]->right = vec[i];
		}
		vec[0]->left = vec[len];
		vec[len]->right = vec[0];
		return vec[0];
	}
};


/*思路二：
 *
 * 不需要使用vector，dfs进行中序遍历，然后使用pre(前一节点), cur(当前节点)
 *
 * 调整指针是的pre->left = cur, cur->right = pre 即可
 *
 * 最后再处理head 和pre的连接
 *
 * 时间复杂度O(n) 空间复杂度O(1)
 * */

class Solution1{
public:
	Node *pre, *head;
	Node* convertTreeToList(Node* root){
		if(!root) return NULL;
		dfs(root);
		head->left = pre;
		pre->right = head;
		return head;
	}

	void dfs(Node* cur){
		if(!cur) return;
		dfs(cur->left);
		// 保存头节点，为最左最小值
		if(pre == NULL)
			head = cur;
		else{
			pre->left = cur;
			cur->right = pre;
		}
		pre = cur;
		dfs(cur->right);
	}
};

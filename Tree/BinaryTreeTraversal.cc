/*
 * 二叉树的遍历方式，递归+非递归
 */

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

/*树的数据结构*/
struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int v = 0): val(v), left(NULL), right(NULL){}
	void Print(){printf("%d ", val);}
};

/*前序遍历-递归*/
void preorderRecursive(BinaryTreeNode* root)
{
	if(!root)
		return;
	root->Print();
	preorderRecursive(root->left);
	preorderRecursive(root->right);
}

/*
 * 前序遍历-非递归
 * 用栈辅助实现
 * */
void preorderNonRecursive(BinaryTreeNode* root)
{
	stack<BinaryTreeNode*> s;	
	s.push(root);
	while(s.size())
	{
		BinaryTreeNode* cur = s.top();
		cur->Print();
		s.pop();
		if(cur->right) s.push(cur->right);
		if(cur->left) s.push(cur->left);
	}
}


/*中序遍历-递归*/
void inorderRecursive(BinaryTreeNode* root)
{
	if(!root)
		return;
	inorderRecursive(root->left);
	root->Print();
	inorderRecursive(root->right);
}


/*
 * 中序遍历-非递归
 * 先走到最左，再回来走右边
 * */
void inorderNonRecursive(BinaryTreeNode* root)
{
	stack<BinaryTreeNode*> s;
	BinaryTreeNode* pNode = root;
	while(pNode || s.size())
	{
		while(pNode)  // 一直往左到底
		{
			s.push(pNode);
			pNode = pNode->left;
		}
		pNode = s.top();
		s.pop();
		pNode->Print();
		pNode = pNode->right;
	}
}


/*后序遍历 - 递归*/
void postorderRecursive(BinaryTreeNode* root)
{
	if(!root) return;
	postorderRecursive(root->left);
	postorderRecursive(root->right);
	root->Print();
}

/*
 * 后序遍历 - 非递归
 * 1. 用两个栈来实现，其中s2保存后序的逆序
 * 2. 用vector保存其逆序
 * */
void postorderNonRecursive(BinaryTreeNode* root)
{
	stack<BinaryTreeNode*> s1;
	stack<BinaryTreeNode*> s2;
	s1.push(root);
	while(s1.size()){
		BinaryTreeNode* pNode = s1.top();
		s2.push(pNode);
		s1.pop();
		if(pNode->left) s1.push(pNode->left);
		if(pNode->right) s1.push(pNode->right);
	}
	while(s2.size()){
		s2.top()->Print();
		s2.pop();
	}
}

void postorderNonRecursive1(BinayrTreeNode* root)
{
	vector<int> v;
	stack<TreeNode*> s;
	s.push(root);
	while(s.size()){
		BinaryTreeNode* tmp = s.top();
		v.emplace_back(tmp->val);
		s.pop();
		if(tmp->left) s.push(tmp->left);
		if(tmp->right) s.push(tmp->right);
	}

	reverse(v.begin(), v.end());
	for(const auto& val : v)
		printf("%d ", val);
}

/*
 * test tree:
 *           0
 *          / \
 *         1   2
 *        / \   \
 *       3   4   5
 *          / \   \
 *         6   7   8
 *
 * preorder:  0 1 3 4 6 7 2 5 8 [root -> left -> right]
 * inorder:   3 1 6 4 7 0 2 5 8 [left -> root -> right]
 * postorder: 3 6 7 4 1 8 5 2 0 [left -> right -> root]
 * */

int main(){
	BinaryTreeNode nodes[9];
	for(int i = 0; i < 9; i++)
		nodes[i] = BinaryTreeNode(i);
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];
	nodes[2].right = &nodes[5];
	nodes[4].left = &nodes[6];
	nodes[4].right = &nodes[7];
	nodes[5].right = &nodes[8];

	// preorder
	printf("Preorder Test:\n");
	printf("Excepted: 0 1 3 4 6 7 2 5 8\n");
	printf("Recursive: ");
	preorderRecursive(nodes);
	printf("\nNon-Recursive: ");
	preorderNonRecursive(nodes);

	// inorder
	printf("\nPreorder Test:\n");
	printf("Excepted: 3 1 6 4 7 0 2 5 8\n");
	printf("Recursive: ");
	inorderRecursive(nodes);
	printf("\nNon-Recursive: ");
	inorderNonRecursive(nodes);

	// postorder
	printf("\nPostorder Test:\n");
	printf("Excepted: 3 6 7 4 1 8 5 2 0\n");
	printf("Recursive: ");
	postorderRecursive(nodes);
	printf("\nNon-Recursive: ");
	postorderNonRecursive(nodes);
	return 0;
}

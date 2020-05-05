/*
 * 树的子结构
 *
 * 输入两棵二叉树A和B，判断B是不是A的子结构。
 * (约定空树不是任意一个树的子结构)
 *
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 *
 * */

class Solution{
public:
	bool isSubstructure(TreeNode* A, TreeNode* B){
		if(!A || !B) return false;
		// dfs每一个节点作为根节点进行check
		return checkSubTree(A, B) || isSubstructure(A->next, B) || isSubstructure(A->right, B);
	}
	bool checkSubTree(TreeNode* A, TreeNode* B){
		if(!B) return true;
		if(!A || A->val != B->val) return false;
		return checkSubTree(A->left, B->left) && checkSubTree(A->right, B->right)
	}
};

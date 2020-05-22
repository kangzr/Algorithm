/*
 * 平衡二叉树
 *
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中
 * 任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *
 * */

/* 思路
 * 根据平衡二叉树的定义，左右子树深度相差不超过1则为平衡树
 *
 * 时间复杂度O(n^2)
 *
 * */

class Solution{
	int TreeDepth(TreeNode* root){
		if(!root) return 0;
		int left = TreeDepth(root->left);
		int right = TreeDepth(root->right);
		return (left > right) ? left + 1 : right + 1;
	}

	int isBalance(TreeNode* root){
		if(!root) return true;
		int left = TreeDepth(root->left);
		int right = TreeDepth(root->right);
		int diff = left - right;
		if(diff > 1 || diff < -1)
			return false;
		return isBalance(root->left) & isBalance(root->right);
	}
};


/* 思路二：提前阻断
 *
 * 对二叉树做dfs，当发现不是平衡树则返回-1，后面的计算便无意义
 *
 * 时间复杂度 O(n)
 *
 * */

class Solution2{
	bool isBalance(TreeNode* root){
		return dfs(root) != -1;
	}

	int dfs(TreeNode* root){
		if(!root) return 0;
		int left = dfs(root->left);
		if(left == -1) return -1;
		int right = dfs(root->rightk);
		if(right == -1) return -1;
		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
	}
};

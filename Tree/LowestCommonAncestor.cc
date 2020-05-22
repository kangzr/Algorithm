// 数的最近公共祖先问题


/*
 *  二叉树
 *
 * 思路
 *  1. 递归查询两个节点p q，如果某节点等于p或q，则返回该节点给父节点
 *  2. 若当前节点左右子树分别包含p和q，即为所求
 *  3. 若当前节点有一个子树返回值为p或q，则返回该值
 *  4. 若当前节点的两个子树返回值都为空，则返回NULL
 * */


class Solution1{
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		if(!root) return NULL;
		if(root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if(left && right) return root;
		return left ? left : right;
	}
};


/*二叉搜索树
 *
 * 思路：利用二叉搜索树的特性
 *
 * 找到第一个root, 使得其值位于p q之间即可
 *
 * 1. 若p q的值都小于当前节点，则进入左子树
 * 2. 若p q的值都大于当前节点，则进入右子树
 * 3. 当前节点位于p q之间，则为所求
 * */

class Solution2{
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		if(!root) return NULL;
		if(p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else if(p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else return root;

	}
};

/*
 * Binary Tree Inorder Traversal
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * */

/* Solution1: Recursive Method
 *
 * */
class Solution1{
public:
	vector<int> res;

	void inorder(TreeNode* root){
		if(!root) return res;
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
	}
	vector<int> inorderTraversal(TreeNode* root){
		inorder(root);
		return res;
	}
};


/* Solution2: Iterative Method*/
class Solution2{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* pNode = root;
		while(s.size() || pNode){
			if(pNode){
				s.push(pNode);
				pNode = pNode->left;
			}
			else{
				pNode = s.top();
				s.pop();
				res.push_back(pNode->val);
				pNode = pNode->right;
			}
		}
		return res;
	}
}

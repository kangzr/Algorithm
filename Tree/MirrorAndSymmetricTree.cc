/*
 *
 * 二叉树的镜像
 *
 */
 
/*解法一:递归*/
class Solution{
public:
	TreeNode* recurseMirrior(TreeNode* root){
		if(!root) return NULL;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		if(root->left) recurseMirrior(root->left);
		if(root->right) recurseMirrior(root->right);
		return root;
	}
};


/*非递归，借助stack*/

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
	       TreeNode* cur = stk.top();
	       stk.pop();
	       TreeNode* tmp = cur->left;
	       cur->left = cur->right;
	       cur->right = tmp;
	       if(cur->left) stk.push(cur->left);
	       if(cur->right) stk.push(cur->right);
	   }
       return root;
    }
};


/*
 * 对称二叉树
 * */
class Solution{
public:
	bool isSymmetric(TreeNode* root){
		return isSymmetricCore(root, root);
	}

	bool isSymmetricCore(TreeNode* root1, TreeNode* root2){
		if(root1 == NULL && root2 == NULL)
			return true;
		if(root1 == NULL || root2 == NULL)
			return false;
		if(root1->val != root2->val)
			return false;
		return isSymmetricCore(root1->left, root2->right) && isSymmetricCore(root1->right, root2->left);
	}
};

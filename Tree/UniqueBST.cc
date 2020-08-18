/*
 * 95. Unique Binary Search Trees II 不同的二叉搜索树 II
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树
 *
 * */


/*思路：递归
 *
 * 遍历每一个数，并生成以该数为根节点的所有bst;
 *
 * */
class Solution{
public:
	vector<TreeNode*> helper(int start, int end){
		vector<TreeNode*> ret;
		if(start > end) ret.push_back(nullptr);
		for(int i = start; i <= end; i++){
			vector<TreeNode*> left = helper(start, i - 1);
			vector<TreeNode*> right = helper(i + 1, end);
			for(auto i : left){
				for(auto r : right){
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
	vector<TreeNode*> generateTrees(int n){
		if(n == 0) return {};
		return helper(1, n);
	}

}

/*
 * 二叉树中和为某一值的路径
 *
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 * 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 *
 *
 * */


//dfs
class Solution{
public:
	vector<vector<int>> res;
	vector<int> path;
	vector<vector<int>> findPath(TreeNode* root, int sum){
		dfs(root, sum);
		return res;
	}

	void dfs(TreeNode* root, int sum){
		if(!root) return;
		sum -= root->val;
		path.emplace_back(root->val);
		if(!root->left && !root->right && !sum)
			res.emplace_back(path);
		dfs(root->left, sum);
		dfs(root->right, sum);
		path.pop_back();
	}
};

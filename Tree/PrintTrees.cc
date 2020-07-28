/*
 * 从上到下打印二叉树
 *
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 *
 * 如果需要每层打印到一行，则用两个遍历记录当前行节点数和下一行节点数即可
 *
 * */
/* 思路；借助deque队列数据结构+BFS思想，从节点push_back, 打印完头节点后， *
 * 再判断其是否,该节点是否又左右节点，有的话，依次入栈
 *
 * 其本质就是广度优先遍历二叉树
 * */



class Solution{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root){
		if (!root) return {};
		queue<TreeNode*> q;
		vector<int> res;
		q.push(root);
		while(q.size()){
			TreeNode* tmp = q.front();
			q.pop()
			res.emplace_back(tmp->val);
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
		return res;
	}
};

/*
 * Z字型打印二叉树
 * 
 * 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印A,
 * 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
 * 其他行以此类推。
 *
 * */

/* 思路：偶数层打印顺序是从右到左，奇数层是从左到右，因此用两个栈实现，
 * 偶数层栈入栈顺序是从左到右，奇数层是从右到左
 * */

class Solution{
public:
	vector<vector<int>> zigzagOrder(TreeNode* root){
		if(!root) return {};
		vector<vector<int>> ret;
		stack<TreeNode*> levels[2];
		int cur = 0, next = 1;
		levels[cur].push(root);
		vector<int> line;
		while(levels[cur].size() || levels[next].size()){
			TreeNode* pNode = levels[cur].top();
			levels[cur].pop();
			line.emplace_back(pNode->val);
			if(cur == 0){
				if(pNode->left) levels[next].push(pNode->left);
				if(pNode->right) levels[next].push(pNode->right);
			}else{
				if(pNode->right) levels[next].push(pNode->right);
				if(pNode->left) levels[next].push(pNode->left);
			}
			if(levels[cur].empty()){
				ret.emplace_back(line);
				line = {};
				cur = 1 - cur;
				next = 1- next;
			}
		}
		return ret;
	}
};

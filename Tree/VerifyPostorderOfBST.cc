/*
 * 二叉搜索树的后序遍历序列
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 * 如果是则返回true，否则返回false。
 * 假设输入的数组的任意两个数字都互不相同。
 * */


/*
 * 思路：
 *
 * 根据二叉搜索树特性，所有左子树值小于根节点，所有右子树值大于根节点
 *
 * 后序遍历最后值为根节点，根据这个值将后序序列分成左右子树，
 *
 * 再check左右左右子树是否满足要求
 *
 * */

class Solution{
public:
	bool verifyPostOrder(vector<int>& postorder){
		if(postorder.empty()) return true;
		return checkOrder(postorder, 0, postorder.size() - 1);
	}

	bool checkOrder(vector<int>& postorder, start, end){
		if(start > end) return true;
		int root = postorder[end];
		int leftIdx = start;
		for(; leftIdx < end; leftIdx++)
			if(postorder[leftIdx] > root)
				break;
		for(int j = leftIdx; j < end; j++)
			if(postorder[j] < root)
				return false;
		// 检查左子树
		bool left = true;
		if(leftIdx > left)
			left = checkOrder(postorder, start, leftIdx - 1);
		// 检查右子树
		bool right = true;
		if(leftIdx < end - 1)
			right = checkOrder(postorder, leftIdx, end - 1);
		return left & right;
	}
};

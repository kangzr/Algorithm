/*
 * 顺时针打印矩阵
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 *
 * 思路：
 * b, t, l ,r 分别表示上下左右的边界，依次打印
 * */
 

class Solution{
public:
	vector<int> printMatrixInCircle(vector<vector<int>>& matrix){
		vector<int> res;
		int rows = matrix.size();
		if(!rows) return res;
		int cols = matrix[0].size();
		int b = 0, t = rows - 1, l = 0, r = cols - 1;
		while(true){
			// 左-->右
			for(int i = 0; i <= r; i++) res.emplace_back(matrix[b][i]);
			if(++b > t) break;

			// 上-->下
			for(int i = 0; i <= t; i++) res.emplace_back(matrix[i][r]);
			if(--r < l) break;

			// 右-->左
			for(int i = r; i >= l; i--) res.emplace_back(matrix[t][i]);
			if(--t < b) break;

			// 下-->上
			for(int i = t; i >= b; i--) res.emplace_back(matrix[l][i]);
			if(++l > r) break;
		}
		return res;
	}
};

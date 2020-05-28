/*
 * 统计全为 1 的正方形子矩阵
 *
 * 给你一个m*n的矩阵，矩阵中的元素不是0就是1，
 * 请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
 *
 * */

/*
 * 状态含义:
 * matrix[i][j]: 表示以(i,j)为右下角的正方形个数
 *
 * 状态转移方程
 * matrix[i][j]=min(min(matrix[i-1][j],matrix[i][j-1]),maxtrix[i-1][j-1])+1
 *
 *
 * */

class Solution{
public:
	int countSquares(vector<vector<int> &matrix){
		int res = 0;
		for(int i = 0; i < matrix.size(); i++){
			for(int j = 0; j < matrix[0].size(); j++){
				if(!matrix[i][j]) continue;
				if(i&&j)
					matrix[i][j]=min(min(matrix[i-1][j],matrix[i][j-1]),maxtrix[i-1][j-1])+1
				res += matrix[i][j];

			}
		}
		return res;
	}
};

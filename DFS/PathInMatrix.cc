/*
 *
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
 *
 * 例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
 * [
 *  ["a","b","c","e"],
 *	["s","f","c","s"],
 *	["a","d","e","e"]
 * ]
 *
 * 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 *
 * 思路(DFS):
 * 1. 遍历矩阵中每一个元素，若该字符等于给定字符串第一个元素，则对该元素执行dfs
 * 2. 将访问过的元素存入temp，并标记为'.'，表明已经访问过
 * 3. 从当前元素的四个方向进行递归
 * 4. 还原temp, 回溯
 *
 * */


class Solution{
public:
	// 四个方向
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};

	bool dfs(vector<vector<char>>& board, int i, int j, int idx, string word)
	{
		if(idx == word.size())  // find
			return true;
		char tmp = board[i][j];
		board[i][j] = '.';
		int row = board.size(), col = board[0].size();
		for(int k = 0; k < 4; k++)
		{
			int x = i + dx[k];
			int y = i + dy[k];
			if(i >= 0 && i < row && j >= 0 && j < col && board[x][y] == word[idx])
				if(dfs(board, x, y, idx + 1, word))
					return true;
				
		}
		board[i][j] = tmp;
		return false
	}

	bool existPath(vector<vector<char>>& board, string word){
		if(board.size() == 0 || board[0].size() == 0)
			return false;
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[i].size(); j++){
				if(dfs(board, i, j, 0, word))
					return true;
			}
		}
	}
	return false
};

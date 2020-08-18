/*
 * 礼物的最大价值
 *
 * 在一个m*n的棋盘的每一格都放有一个礼物,每个礼物都有一定的价值(价值大于0）
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格,
 * 直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，
 * 请计算你最多能拿到多少价值的礼物？
 *
 * */


/*
 * 思路一：借助二维数组
 *
 * dp[i][j] 表示到达位置(i, j)所能获得的最大礼物值
 *
 * 状态方程: dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * 边界条件：第一行只能从左至右，第二行只能从上至下
 *
 * */
class Solution1{
public:
	int maxGiftValue(vector<vector<int>> &grid){
		if(grid.empty() || grid[0].empty()) return 0;
		int cols = grid.size(), rows = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, grid[0][0]));
		for(int i = 1; i < cols; i++)
			dp[0][i] = dp[0][i-1] + grid[0][i];
		for(int i = 1; i < rows; i++)
			dp[i][0] = dp[i-1][0] + grid[i][0];
		for(int i = 1; i < rows; i++)
			for(int i = 1; i < cols; i++)
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		return dp[rows-1][cols-1];
	}
};

/* 思路2: 优化成一维数组
 *
 * 只需保留上一行dp值即可
 * dp[j] 表示上一行第j列的最大值
 * dp[j] = max(dp[j-1], dp[j]) + grip[i][j]
 *
 * 边界条件，第一行只能从左至右累加
 *
 * */

class Solution2{
public:
	int maxGiftValue(vector<vector<int>> &grid){
		if(grid.empty() || grid[0].empty()) return 0;
		vector<int> dp(grid[0].begin(), grid[0].end());
		for(int j = 1; j < grid[0].size(); j++)
			dp[j] += dp[j-1];
		for(int i = 1; i < grid.size(); i++){
			dp[0] += grid[i][0]
			for(int j = 1; j < grid[0].size(); j++)
				dp[j] = max(dp[j-1], dp[j]) + grip[i][j];
		}
		return dp.back()
	}
};

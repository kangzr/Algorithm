/* 机器人的运动范围
 *
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
 * 它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 *
 * 思路(dfs):
 * 从(0, 0)开始向右和下搜索即可
 *
 * */

/// 优化版
class Solution{
	private:
		int m, n, k;
	public:
		int s = 0;
		int movintCount(int n, int m, int k){
			this->m = m, this->n = n, this->k = k;
			vector<vector<int>> visited(n, vector<int>(m, 0));
			return dfs(0, 0, visited);
		}
		int dfs(int x, int y, vector<vector<int>>& v){
			if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] || getNum(x, y) > k)
				return;
			v[x][y] = 1;
			return 1 + dfs(x + 1, y, v) + dfs(x, y + 1, v);
		}

};

class Solution1{
	private:
		int m, n, k;
	public:
		int getNum(int x, int y)
		{
			int res = 0;
			while(x || y){
				if(x)
				{
					res += x % 10;
					x /= 10;
				}
				if(y)
				{
					res += y % 10;
					y /= 10;
				}
			}
			return res;
		}
		int movingCountCore(int x, int y){
			int count = 0;
			if(x >= 0 && x <= m && y >= 0 && y <= n && k >= getNum(x, y) && !visited[x][y]){
				count = 1 + movingCountCore(x - 1, y) + movingCountCore(x + 1, y) + movingCountCore(x, y - 1) + movingCountCore(x, y + 1);
			}
			return count;
		}
		int movingCount(int m, int n, int k){
			this->m = m, this->n = n, this->k = k;
			vector<vector<int>> visited(m, vector<int>(n, 0));
			return movingCountCore(0, 0);
		}

};

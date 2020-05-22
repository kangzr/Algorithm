/*
 * n个骰子的点数
 *
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
 * 输入n，打印出s的所有可能的值出现的概率。
 *
 * */


/* 思路
 *
 * 定义dp[n][i] 为前n个骰子和达到i的总个数
 * 转移方程：dp[n][i] = dp[n-1][i-1] + dp[n-1][i-2] + ... + dp[n-1][i-6]
 * 初始条件 dp[0][0] = 1;
 *
 * */

class Solution{
public:
	vector<double> probability(int n){
		vector<vector<int>> dp(n + 1, vector<int>(6*n + 1, 0));
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= i * 6; j++){
				for(int k = 1; k <= 6; k++){
					if(j >= k)
						dp[i][j] += dp[i-1][j-k];
				}
			}
		}
		double total = pow(6, n);
		vector<double> res;
		for(int i = n; i <= n * 6; i++)
			res.push_back(dp[n][i] / total);
		return res;
	}
};

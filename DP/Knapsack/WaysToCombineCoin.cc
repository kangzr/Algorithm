/*
 * 硬币
 *
 * 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，
 * 编写代码计算n分有几种表示法 (结果可能会很大 你需要将结果模上1000000007)
 *
 * */


/* 思路：完全背包
 *
 * 状态含义:
 * dp[j]: 表示前i - 1轮构成j分的计数
 *
 * 状态转移:
 * dp[j] = dp[j] + dp[j - coin]; 
 * 其中左边为第i轮构成j分的计数, 等于前i-1轮计数(不取当前coin) + 前i-1构成
 * j-coin计数(取当前coin)
 *
 *
 * */

class Solution{
private:
	static constexpr int mod = 1e9 + 7;
	static constexpr int coins[4] = {25, 10, 5, 1};
public:
	int waysToCombineCoin(int n){
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for(int i = 0; i < 4; i++){
			int coin = coins[i];
			for(int j = coin; j <= n; j++)
				dp[j] = (dp[j] + dp[j-coin]) % mod;
		}
		return dp[n];
	}
};

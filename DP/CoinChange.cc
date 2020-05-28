/*
 * 凑零钱问题
 *
 * 有k中面值的硬币,面值分别为c1,c2,...,ck,最少需要几枚硬币能凑出总数amount
 * 其中，硬币数量无限，若凑不出则返回-1
 *
 * */

/*
 * 解法一：暴力递归
 *
 * 时间复杂度: O(k * n ^ k)
 * */

int coinChange(vector<int> &coins, int amount){
	return helper(coins, amount);
}

int helper(vector<int> &coins, int amount){
	if(amount == 0) return 0;
	if(amount < 0) return -1;
	int ret = INT_MAX;
	for(auto coin : coins){
		int sub = helper(coins, amount - coin);  // 子问题
		if(sub == -1) continue;
		ret = min(ret, 1 + sub);
	}
	return ret ? ret != INT_MAX : -1;
 }

/*
 * 解法2: 带备忘录的递归
 *
 * 状态转移方程
 * 
 *         | 0, n = 0
 * dp(n) = | -1, n < 0
 *         | min(dp[n-coin] + 1 | coin属于coins), n > 0
 *
 * 时间复杂度 O(kn)
 * */

int coinChange(vector<int> &coins, int amount){
	unordered_map<int, int> memo;
	return helper(coins, amount, memo);
}

int helper(vector<int> &coins, int amount, unordered_map<int, int> &memo){
	if(amount == 0) return 0;
	if(amount < 0) return -1;
	if memo.count(amount) return memo[amount];
	int ret = INT_MAX;
	for(int coin : coins){
		int sub = helper(coins, amount - coin, memo);
		if(sub == -1) continue;
		ret = min(ret, 1+sub)	
	}
	memo[amount] = ret ? ret != INT_MAX : -1;
	return memo[amount];
}


/*
 * 解法三：循环迭代, 自底而上
 *
 * dp[i] 当目标金额为i时，至少需要几枚硬币
 *
 * */

int coinChange(vector<int> &coins, int amount){
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;
	for(int i = 0; i <= amount; i++){
		for(int coin : coins){
			if(i - coin < 0) continue;
			dp[i] = min(dp[i], 1 + dp[i - coin]);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

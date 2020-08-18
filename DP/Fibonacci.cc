/*
 * 斐波拉契问题
 *
 * f(1) = f(2) = 1
 * f(n) = f(n-1) + f(n-2) (n > 2)
 *
 * */

/*
 * 解法一：暴力递归
 *
 * 时间复杂度O(2^n)   由于子问题个数为递归树节点数 而二叉树指数级别为
 *
 * 缺点：存在大量重叠子问题
 *
 * */

int fib(int n){
	if(n < 1) return 0;
	if(n < 3) return 1;
	return f(n-1) + f(n-2);
}


/*
 * 解法二：带备忘录的递归，自顶而下
 *
 * 使用数组保存已经计算出来的值来进行剪枝，避免重复计算子问题
 *
 * 时间复杂度: O(n) 空间复杂度: O(n)
 *
 * */
int fib(int n){
	if (n < 1) return 0;
	vector<int> memo(n + 1, 0);
	return helper(n, memo);
}

int helper(int n, vector<int> &memo){
	int (n == 1 || n === 2)	return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
	return memo[n];
}


/*
 * 解法三：动态规划，自底向上, 循环
 *
 * 从f(1), f(2) 向上推
 *
 * 状态转移方程
 *
 * f(n) = 1, n = 1, 2
 * f(n) = f(n-1) + f(n-2), n>2
 *
 * 时间复杂度：O(n) 空间复杂度：O(n)
 *
 * */

int fib(int n){
	vector<int< dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for(int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}


/*
 * 解法三：动态规划，空间优化
 *
 * 只需记录前两个状态，无需记录所有状态，可将空间复杂度降至O(1)
 *
 * */

int fib(int n){
	if(n < 3) return 1;
	int pre = 1, cur = 1;
	for(int i = 3; i <= n; i++){
		int tmp = pre + cur;
		pre = cur;
		cur = tmp;
	}
	return cur;
}

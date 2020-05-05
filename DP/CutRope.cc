/*
 * 剪绳子
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1
 * 每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少?
 *
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 *
 * */


/* 一：动态规划
 * dp[i] ： 表示长度为i的绳子，剪成若干断后，各段长度乘积的最大值
 * 时间复杂度O(n^2)，空间复杂度O(n)
 * */
class Solution1{
public:
	int cutRope(int n){
		if (n <= 3) return n - 1;

		vector<int> dp(n + 1, 0);
		dp[1] = 1, dp[2] = 2, dp[3] = 3;
		for(int i = 4; i <= n; i++){
			int max = 0;
			for(int j = 1; j <= i / 2; j++){
				int tmp = dp[j] * dp[i - j];
				if(tmp > max)
					max = tmp;
				dp[i] = max;
			}
		}
		return dp[n];
	}

};


/*
 *贪婪算法
 * 2(n-2) > n  3(n-2) > n, n >= 5
 * */

class Solution2{
public:
	int cutRope(int n){
		if (n <= 3) return n - 1;
		// 尽可能多的剪3
		int timesof3 = n / 3;
		if (n - timesof3 * 3 == 1)
			timesof3--;
		// 考虑4的情况 因为2*2 > 3 * 1
		int timesof2 = (n - timesof3 * 3) / 2;
		return pow(2, timesof2) * pow(3, timesof3);

		/*
		int a = n / 3, b = n % 3;
		if(b == 0) return pow(3, a);
		if(b == 1) return pow(3, a - 1) * 4;
		if(b == 2) return pow(3, a) * 2;
		*/
};


/*
 * 丑数
 *
 * 只包含因子2,3和5的数称作丑数(Ugly Number), 
 * 求按从小到大的顺序的第n 个丑数。
 *
 * */

/*思路
 *
 * 用一个数组保存丑数，用三个指针p2, p3, p5分别指向要乘2, 3, 5的指针
 * min(2*dp[p2], 3*dp[p3], 5*dp[p5]) 为下一个丑数，并将相应的指针前移一位
 * 
 * */

class Solution{
public:
	int uglyNumber(int n){
		vector<int> dp(n, 1);
		int p2 = 0, p3 = 0, p5 = 0, next = 1;
		while(next < n){
			dp[next] = min(min(2*dp[p2], 3*dp[p3]), 5*dp[p5]);
			if(2*dp[p2] == dp[next]) p2++;
			if(3*dp[p3] == dp[next]) p3++;
			if(5*dp[p5] == dp[next]) p5++;
			next++;
		}
		return dp[next-1];
	}
};

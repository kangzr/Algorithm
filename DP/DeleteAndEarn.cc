/*
 * 删除与获得点数
 *
 * 给定一个整数数组 nums ，你可以对它进行一些操作。
 *
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
 * 之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
 *
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 *
 * 输入: nums = [3, 4, 2]
 * 输出: 6
 *
 * */


/* 思路一: 以数组下标作为索引
 *
 * dp数组含义:
 * dp[i][0]: 第i个数不拿获得的最大点数
 * dp[i][1]: 第i个数拿时获得的最大点数
 *
 * - 先排序
 * - 当第i个数与第i-1个数相同:
 *		1) dp[i][1] = dp[i-1][1] + nums[i];
 *		2) dp[i][0] = dp[i-1][0]
 * - 当第i个数与第i-1个数不同时:
 *		1) 第i个数比i-1大1: dp[i][1] = dp[i-1][0]+nums[i],(肯定拿i大)
 *					  否则: dp[i][1] = max(dp[i-1][1],dp[i-1][0])+nums[i]
 *		2) dp[i][0] = max(dp[i-1][1],dp[i-1][0])
 *
 *	时间复杂度: O(n * logn), 空间复杂度O(n)
 *
 * */
class Solution{
public:
	int deleteAndEarn(vector<int> &nums){
		int len = nums.size();
		if(len <= 0) return 0;
		vector<vector<int>> dp(len, vector<int>(2, 0));
		sort(nums.begin(), nums.end());
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		for(int i = 1; i < n; i++){
			if(nums[i] == nums[i-1]){
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][1] + nums[i];
			}
			if(nums[i] - nums[i-1] == 1)
				dp[i][1] = dp[i-1][0] + nums[i];
			else
				dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + nums[i];
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		}
		return max(dp[n-1][0], dp[n-1][1]);
	}
};


/* 思路二：以数组中的值作为索引
 * 
 * 以数组中的值作为索引时, 第i个数与第i-1个数具有天然的+1性
 *
 * 转移方程
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1])
 * dp[i][1] = dp[i-1][0] + i * counts[i]
 *
 * 时间复杂度O(max(nums[i]))
 * 空间复杂度O(max(nums[i]))
 *
 * */

class Solution2{
public:
	int deleteAndEar(vector<int> &nums){
		if(nums.empty()) return 0;
		int N = *max_element(nums.begin(), nums.end());
		vector<int> counts(N+1, 0);
		for(int x : nums) ++counts[x];
		vector<vector<int>> dp(N+1, vector<int>(2, 0));
		dp[1][0] = 0;
		dp[1][1] = counts[i];

		for(int i = 2; i <= N; i++){
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + nums[i];
		}
		return max(dp[N][0], dp[N][1]);
	}
};

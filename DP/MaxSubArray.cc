/*
 * 连续子数组的最大和
 *
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数
 * 组成一个子数组。求所有子数组的和的最大值。
 *
 * 要求时间复杂度为O(n)。
 *
 *
 * */

/*思路一：
 *
 * dp[i] = max(dp[i] + nums[i], dp[i])
 *
 * 其中dp[i]含义为第i个数时的最大子数组和
 *
 * 时间复杂度O(n)  空间复杂度O(n)
 * */

class Solution1{
public:
	int maxSubArray(vector<int>& nums){
		if(nums.empty()) return 0;
		vector<int> dp(nums.size(), nums[0]);
		int ans = dp[0];
		for(int i = 1; i < nums.size(); i++){
			dp[i] = max(dp[i - 1] + nums[i], dp[i]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};


// 思路二，只保留最大值(即dp[i])，将空间复杂度降至O(1)
class Solution1{
public:
	int maxSubArray(vector<int>& nums){
		if(nums.empty()) return 0;
		int dp = nums[0];
		int ans = dp;
		for(int i = 1; i < nums.size(); i++){
			dp[i] = max(dp + nums[i], dp);
			ans = max(ans, dp);
		}
		return ans;
	}
};

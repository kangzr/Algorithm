/*
 * 最长递增子序列
 *
 * 给定一个无序数组，找出其中最长上升子序列长度(不一定连续)
 * 
 * 输入：[10, 9, 2, 5, 3, 7, 101]
 * 输出：4 ([2, 3, 7, 101])
 *
 * */

/* 思路一:
 *
 * 1. 子问题状态: dp[i], 表示以nums[i]结尾的最长上升子序列
 * 2. 状态转移方程: dp[i] = max(dp[j]), j < i 且 nums[i] > nums[j]
 *
 * base dp[i] = 1, 每一个位置的最小值都至少为1
 *
 * 时间复杂度：O(n^2); 空间复杂度: O(n)
 *
 * */

class Solution{
public:
	int longestIncreaseSequence(vector<int> &nums){
		int len = nums.size();
		if(len <= 0) return 0;
		vector<int> dp(len, 1);
		for(int i = 1; i < len; i++){
			for(int j = 0; j < i; j++){
				if(nums[i] > nums[j])
					dp[i] = max(dp[j] + 1, dp[i]);
			}	
		}

		res = 0;
		for(int i = 0; i < len; i++)
			if(dp[i] > res)
				res = dp[i];
		return res;
	}
};


/*思路二：二分查找
 * 
 * 遍历数组，对其进行分堆，放入数必须小于堆顶元素，已有堆不满足，则开启新堆
 * , 并且入堆顺序是从最早建立的堆开始遍历，最长递增子序列即为堆的数量
 *
 * */

class Solution2{
public:
	int LIS(vector<int> &nums){
		int len = nums.size();
		vector<int> top(len, 0);
		int piles = 0;  // 牌堆数
		for(int i = 0; i < len; i++){
			int poker = nums[i];
			int left = 0, right = piles;
			while(left < right){
				int mid = left + (right - left) / 2;
				if(top[mid] < poker)
					left = mid + 1;
				else
					right = mid;
			}
			if(left == piles)
				piles++;
			top[left] = poker
		}
		return piles;
	}
};

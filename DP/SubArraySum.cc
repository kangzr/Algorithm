/*
 * 连续的子数组和
 *
 * 给定一个包含非负数的数组和一个目标整数 k，
 * 编写一个函数来判断该数组是否含有连续的子数组，
 * 其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。
 *
 * 输入: [23,2,4,6,7], k = 6
 * 输出: True
 *
 * */


/* 思路1：前缀和+unordered_map
 *
 * 若前缀和Pre[i] % k == Pre[j] % k，两个前缀和之差即为k的倍数
 * 如 [a, b, c, d, e] (a+b) % k == (a+b+c+d) % k, 则(c+d)必为k的倍数
 *
 * */

class Solution{
public:
	bool checkSubArraySum(vector<int> &nums, int k){
		int sum = 0;
		unordered_map<int, int> mp;
		mp.insert({0, -1});
		for(int i = 0; i < nums.size(); i++){
			sum += nums[i];
			if(k) sum %= k;
			if(mp.count(sum)){
				if(i - mp[sum] > 1) return true;
			}
			else mp.insert({sum, i});
		}
		return false;
	}
}


/*思路2: 前缀和+intMap
 *
 * 1. 保存所有的前缀和
 * 2. 通过k-v形式，把余数相同的index放入一个vector中，
 * 3. 遍历每一个前缀和, check是否存在余数相同的索引值(值俩前缀和)
 *
 * */

class Solution{
public:
	bool checkSubArraySum(vector<int> &nums, int k){
		int n = nums.size();
		if(n == 0) return false;
		if(k == 0){
			for(int i = 1; i < n; i++)
				if(nums[i-1] == nums[i] && nums[i] == 0)
					return true;
			return false;
		}
		vector<int> preSum(n + 1, 0);
		unordered<int, vector<int>> mp;
		for(int i = 1; i <= nums.size(); i++){
			preSum[i] = preSum[i-1] + nums[i - 1];
			mp[preSum[i] % k].push_back(i);
		}
		mp[preSum[0] % k].push_back(0);
		for(int i = 1; i <= nums.size(); i++){
			for(auto iter : mp[preSum[i] % k])
				if(iter < i - 1) return true;
		}
		return false;
	}
}

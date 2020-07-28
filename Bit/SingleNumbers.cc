/*
 * 数组中数字出现的次数
 *
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。
 * 要求时间复杂度是O(n)，空间复杂度是O(1)。
 *
 * */


/* 思路：异或(任何一个数与自身的异或都为0)
 *
 * 0 ^ 0 = 0     1 ^ 0 = 1 
 *
 * 1. 对数组中所有元素进行一次异或，得到的值即为 res = a ^ b, a b即为所求
 * 2, 从右往左找到res中的第一位为1的位得到mask(改位用于区别ab)
 * 3. 再对数据进行所有元素进行一次异或，mask位为1的与a异或，或则与b异或
 *
 * 也即是将数组分成两组，其中一组包含a，另一组包含b
 * 且两组数中只有ab只出现一次，其他均为两次。
 * 
 * 因此把问题转化为求数组中只出现一次的数字(其余均出现两次)
 *
 * 时间复杂度O(n), 空间复杂度O(1)
 * */

class Solution{
public:
	vector<int> singleNumbers(vector<int> nums){
		int res = 0, a = 0, b = 0, mask = 1;
		for(int n : nums) res ^= n;
		while((res & mask) == 0) mask <<= 1;
		for(int n : nums){
			if(n & mask) a ^= n;
			else b ^= n;
		}
		return {a, b};
	}
};



/* 
 * 数组中数字出现的次数 II
 *
 * 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
 * 请找出那个只出现一次的数字。
 *
 * */


/* 思路：
 *
 * 如果某个数出现了三次，则其一定能被3整除，且其每一位相加也一定是三的倍数
 *
 * 根据这一特性，可以找出只出现一次数字位为1的每一位，进而构建该数
 *
 * 因为，如果出现一次数位为1的话，数组中所有数该位的和一定不能被3整除
 *
 * */

class Solution2{
public:
	int singleNumber(vector<int> nums){
		int ans = 0;
		for(int i = 0; i < 31; i++){
			int cnt = 0;  // 记录所有数某一位为1的和
			for(int n : nums){
				if(n & (1 << i)) cnt++;
			}
			if(cnt % 3) ans ^= (1 << i);
		}
		return ans;
	}
};

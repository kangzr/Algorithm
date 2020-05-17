/*
 * 把数字翻译成字符串
 *
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成“a”, 1翻译成“b”
 * ，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
 * 请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 *
 * */

/* 思路：
 *
 * dp[i] 表示第i+1位的翻译方法,
 *
 * 状态转移方程
 *         | dp[i-1]     // num[i]无法与num[i-1]组成字符
 * dp[i] = |
 *         | dp[i-1] + dp[i-2]  // num[i]可以与num[i-1]组成字符
 * 
 * 优化不需要使用dp数组，用两个变量存储前两个位置的值即可(类似斐波拉契)
 * */

class Solution{
public:
	int translateNum(int num){
		if(num <= 10) return 1;
		vector<int> nums;
		while (num){
			nums.push_back(num % 10);
			num /= 10;
		}
		reverse(nums.begin(), nums.end());
		int ans = 0, num1 = 1, num2 = 1;
		for(int i = 1; i < nums.size(); i++){
			if(nums[i-1] == 0 || nums[i-1]*10 + nums[i] > 25)
				ans = num1;
			else
				ans = num1 + num2;
			num2 = num1;
			num1 = ans;
		}
		return ans;
	}
};


// 解法二：回溯
class Solution2{
public:
	int backtrace(string& str, int pos){
		int n = str.size();
		if(pos == n) return 1;
		if(pos == n - 1 || str[pos] == '0' || str.substr(pos, 2) > "25")
			return backtrace(str, pos + 1);
		return backtrace(str, pos + 1) + backstrace(str, pos + 2);
	}
	int traslateNum(int num){
		string str = to_string(num);
		return backtrace(str, 0);
	}
};

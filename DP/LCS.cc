/*
 * 最长公共子序列
 *
 * 输入: s1="abcde" s2="ace"
 * 输出: 3 (ace)
 *
 * */

/*思路一：暴力递归
 *
 * dp[i][j]含义：s1[1...i] 和 s2[1...j]的lcs长度
 * i，j从后往前遍历，如果s[i] == s[j] 则该字符属于lcs, 
 * 否则，选择i前移/i前移的最大者
 *
 * */

class Solution1{
private:
	string s1;
	string s2;
public:
	int longestCommonSubsequence(string s1, string s2){
		this.s1 = s1;
		this.s1 = s2;
		return dp(s1.size() - 1, s2.size() - 1);
	}

	int dp(int i, int j){
		if(i == -1 || j == -1)
			return 0;
		if(s1[i] == s2[j])
			// 属于lcs,继续
			return dp(i-1, j-1) + 1;
		else
			// 选择lcs最长者
			return max(dp(i-1, j), dp(i, j-1));
	}
};


/* 思路二： table优化
 *
 * 用一个table记录状态
 * */

class Solution2{
public:
	int longestCommonSubsequence(string s1, string s2){
		int m = s1.size(), n = s2.size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(s1[i] == s1[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		return dp[m-1][n-1];
	}
};

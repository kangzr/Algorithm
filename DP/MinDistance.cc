/*
 * 编辑距离
 *
 * 给定两个字符串s1, s2, 计算将s1转换为s2所需要的最小操作数
 * 你可以对字符串进行以下操作：插入，删除，替换
 *
 * */

/*
 * 思路一: 递归
 * 
 * if s1[i] == s2[j]: skip
 * else  三选一
 *    dp(i, j - 1)  插入
 *    dp(i-1, j)  删除
 *    dp(i-1, j-1)  替换
 *
 *  时间复杂度: O(max(2^n), 2^m), 空间复杂度: O(1)
 *
 * */

class Solution{
private:
	string s1;
	string s2;
public:
	int minDistance(string s1, string s2){
		this.s1 = s1;
		this.s2 = s2;
		int i = s1.size(), j = s2.size();
		return dp(i, j);
	}

	int dp(int &i, int &j){
		if(i == -1) return j + 1;
		if(j == -1) return i + 1;
		if(s1[i] == s2[j]){
			return dp(i - 1, j - 1);
		}
		else{
			return min(min(dp(i, j - 1), dp(i - 1, j)), dp(i-1, j-1)) + 1;
		}
	}
};


/*思路二：dp table
 *
 * 利用备忘录优化
 *
 * dp[i][j]: 存储s1[0..i-1] 和 s2[0..j-1]最小编辑距离
 *
 * 时间复杂度：O(m*n), 空间复杂度: O(m*n)
 *
 * */

class Solution{
public:
	int minDistance(string s1, string s2){
		int m = s1.size();
		int n = s2.size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for(int i = 1; i <= m; i++)
			dp[i][0] = i;
		for(int i = 1; i <= m; i++)
			dp[0][i] = i;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				if(s1[i] == s2[j])
					dp[i][j] = dp[i-1][j-1];
				else{
					dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
				}
			}
		}
		return dp[m][n];
	}
};

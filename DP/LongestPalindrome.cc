/* 最长回文子串
 *
 *
 * 给定一个字符串s, 找到s中最长的回文子串。你可以假设s的最大长度为1000。
 *
 * 输入: "babad"
 * 输出: "bab"
 *
 * */

/*
 * dp[j][i]: 表示从j到i之间的子串是否为回文
 *
 * 状态转移：
 * dp[j][i] = (i - j < 3 || dp[j+1][i-1]) && (s[j] == s[i])
 *
 * */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	string longestPalindrome(string s){
		int len = s.size();
		if(len <= 1) return s;
		vector<vector<int>> dp(len, vector<int>(len, 0));
		for(int i = 0; i < len; i++)
			dp[i][i] = 1;
		int maxLen = 1, left = 0;
		for(int i = 1; i < len; i++){
			for(int j = 0; j < i; j++){
				if(s[i] == s[j] && (i - j < 3 || dp[j+1][i-1])){
					dp[j][i] = 1;
					if(maxLen < i - j + 1){
						maxLen = i - j + 1;
						left = j;
					}
				}
			}
		}
		return s.substr(left, maxLen);
	}
};


int main(){
	Solution s;
	cout << s.longestPalindrome("baabaad") << endl;
	return 0;
}

/*
 * 翻转单词顺序
 *
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。
 * 例如输入字符串"I am a student. "，则输出"student. a am I"。
 *
 * */


/* 思路：两次反转
 *
 * 1. 反转每个单词
 * 2. 反转整个字符串
 *
 * ps: 考虑开头结尾空格以及中间多空格的情况, 否则无法ac
 *
 * */

class Solution{
public:
	string reverseWords(string s){
		int k = 0;  // 用于反转后得到的字符索引, 用于过滤空格
		for(int i = 0; i < s.size(); i++){
			while(i < s.size() && s[i] == ' ') i++;  // 第一个非空字符
			if(i == s.size()) break;
			int j = i;
			while(j < s.size() && s[j] != ' ') j++;  // 下一个空格
			reverse(s.begin() + i, s.begin() + j);  // 反转单词
			if(k) s[k++] = ' ';
			while(i < j) s[k++] = s[i++];
		}
		s.erase(s.begin() + k, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
};

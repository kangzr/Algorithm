/*
 *
 *正则表达式匹配
 *
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，'*'表示它前面的字符可以出现任意次(>=0)
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 *
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配
 *
 */
 

 /*思路一*/

class Solution{
public:
	bool isMatch(char* s, char* p){
		if(!*p) return !*s; // p为空，s为空则匹配，否则不匹配
		bool firstMatch = *s && (*s == *p || *p == '.');  // 第一个字符是否匹配
		// == "*"，需要考虑匹配0个字符情况以及匹配多个情况
		if(*(p+1) == '*')
			return isMatch(s, p + 2) || (firstMatch && isMatch(++s, p);
		else
			return firstMatch && isMatch(++s, ++p);
	}
};

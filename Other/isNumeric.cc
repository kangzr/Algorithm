/*
 * 表示数值的字符串
 *
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数)。
 * 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值
 * 但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。
 *
 * */

/*解题思路：
 * 1. skip space
 * 2. 判断前部分是不是数值
 * 3. 是否为‘.’， 是的话，考虑.123 / 233. / 23.23等情况
 * 4. 是否为'e/E', 是的话，考虑则前后都必须为数值
 * */

class Solution{
public:
	int idx = 0;
	void skipSpace(string s){
		while(idx < s.size() && s[idx] == ' ')
			idx++;
	}
	bool isNumeric(string s){
		skipSpace(s);
		bool numeric = scanInteger(s);
		if (s[idx] == '.'){
			idx++;
			// . 后面不可带符号
			numeric = numeric || scanUnSignedInteger(s)
		}
		if(s[idx] == 'e' || s[idx] == 'E'){
			idx++;
			// e 后面可以带符号
			numeric = numeric && scanInteger(s);
		}
		skipSpace(s);
		return numeric && idx == s.size();
	}
	bool scanInteger(string s){
		if(s[idx] == '-' || s[idx] == '+')
			idx++;
		scanUnSignedInteger(s);
	}
	bool scanUnSignedInteger(string s){
		int oldIdx = idx;
		while(s[idx] != '\0' && s[idx] >= '0' && s[idx] <= '9')
			idx++;
		return idx > oldIdx;
	}
};

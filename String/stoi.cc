/*
 * 把字符串转换成整数
 *
 * 写一个函数StrToInt 实现把字符串转换成整数这个功能.
 * 不能使用atoi或者其他类似的库函数。
 *
 * 1. 丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止
 * 2. 第一个非空字符为正负号时，则将该符号与之后面尽可能多的连续数字组合起来
 * 3. 有效整数部分后面的无效部分，忽略
 * 4. 无法进行有效转换时，返回0
 * 5. 数值范围: INT_MAX (2^31 − 1)或INT_MIN(−2^31) 
 * */


// 思路一
class Solution{
public:
	int my_stoi(string s){
		int i = 0;  // 索引值
		int flag = false;  // 符号位
		long long ret = 0;  // 结果
		// 去开头空格
		while(s[i] == ' ') i++;
		// 符号位判定
		if(s[i] == '+') i++;
		else if(s[i] == '-'){
			i++;
			flag = -1;
		}
		for(; i < s.size(); i++){
			if(isdigit(s[i])){
				ret = ret * 10 + s[i] - '0';
				if(flag * ret > INT_MAX) return INT_MAX;
				if(flag * ret < INT_MIN) return INT_MIN;
			}else break;  // 无效部分去除
		}
		return flag * ret;
	}
};

/*
 * 思路二：有限状态机
 *
 * 四种状态 start(初始), signed(符号), digit(数字), end(结束)
 * 初始为start，遇空格继续保持start，遇符号进入signed状态，遇数字进入digit状态,否则进入end
 * signed状态，遇数字进入digit，否则进入end
 * digit状态，遇数字保持digit，否则进入end
 * end，end
 * */

class Automation{
private:
	string state = "start";
	unordered_map<string, vector<string>> table{
		{"start", {"start", "signed", "digit", "end"}},
		{"signed", {"end", "end", "digit", "end"}},
		{"digit", {"end", "end", "digit", "end"}},
		{"end", {"end", "end", "end", "end"}},
	};

	int getCol(char ch){
		if(isspace(ch)) return 0;
		if(ch == '+' || ch == '-') return 1;
		if(isdigit(ch)) return 2;
		return 3;
	}
public:
	int sign = 1;
	long ans = 0;
	void work(char ch){
		state = table[state][getCol(ch)];
		if(state == "digit"){
			ans = ans * 10 + ch - '0';
			ans = sign == 1 ? min(ans, (long)INT_MAX) : max(ans, -(long)INT_MIN);
		}
		else if(state == "signed")
			sign = c == '+' ? 1 : -1;
	}

}

class Solution{
	int atoi(string s){
		Automation at;
		for(auto ch : s)
			at.work(ch);
		return at.sign * at.ans;
	}
};


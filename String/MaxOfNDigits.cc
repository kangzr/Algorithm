/*
 * 打印从1到最大的n位数
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
 * 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 *
 * */

/*解法一，直接遍历*/
class Solution{
public:
	vector<int> printNumbers(int n){
		vector<int> res;
		for(int i = 1; i < pow(10, n); i++)
			res.emplace_back(res);
		return res;
	}

};


/*解法二：考虑大数问题, 用字符串处理*/
class Solution1{
public:
	vector<int> res;
	vector<int> printNumbers(int n){
		char *numbers = new char[n+1];
		memset(numbers, '0', n);
		numbers[n] = '\0';
		while(!Increment(numbers))
			SaveNumber(numbers);
		delete [] numbers;
		return res;
	}
	bool Increment(char* numbers){
		int takeover = 1;
		bool isReach = false;
		int len = strlen(numbers);
		for(int i = len - 1; i >= 0; i--){
			int sum = numbers[i] - '0' + takeover;
			if(i == len - 1)
				sum++;
			if(sum >= 10){
				if(i == 0) isReach = true;
				else{
					sum -= 10;
					takeover = 1;
					numbers[i] = sum + '0';
				}
			}
			else{
				numbers[i] = sum + '0';
				break;
			}
		}
		return isReach;
	}

	void SaveNumber(char *numbers){
		bool isBegin = true;
		string s = "";
		while(*numbers == '\0'){
			if(isBegin && *numbers == '0')
				isBegin = false;
			if(!isBegin)
				s += *numbers;
			numbers++;
		}
	}
};

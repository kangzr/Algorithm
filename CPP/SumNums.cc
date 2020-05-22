/*
 * 求1+2+…+n
 * 求1+2+...+n 要求不能使用乘除法 for while if else switch case等关键字
 * 及条件判断语句（A?B:C）。
 *
 * */

/*思路一：构造函数
 *
 * */

class Sum{
public:
	Sum(){
		_sum += _i;
		++_i;
	}

	static void Init(){
		_sum = 0;
		_i = 1;
	}

	static int GetNum(){
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};

int Sum:_sum = 0:
int Sum::_i = 1;

class Solution{
public:
	int sumNums(int n){
		Sum::Init();
		Sum *arr = new Sum[n];
		delete [] arr;
		return Sum::GetNum();
	}
};


/*
 * 不用加减乘除做加法
 *
 *
 * 写一个函数，求两个整数之和，要求在函数体内不得使用 
 * “+”、“-”、“*”、“/” 四则运算符号。
 *
 * */

class Solution1{
public:
	int add(int a, int b){
		int sum;  // 无进位和
		int carry;  // 进位
		while(b != 0){
			sum = a ^ b;  // 异或操作得到无进位和
			carry = (unsigned int) (a & b) << 1;  // 与操作后移位得到进位值
			a = sum;
			b = carry;
		}
		return a;
	}
};


/*不使用临时变量交换两数的值*/

int swap1(int a, int b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int swap2(int a, int b){
	a = a + b;
	b = a - b;
	a = a - b;
}

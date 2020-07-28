/*
 * 数值的整数次方
 *
 *
 * 实现函数double Power(double base, int exponent)，求base的exponent次方。
 * 不得使用库函数，同时不需要考虑大数问题。
 *
 * 思路：快速二次幂
 * n为偶数 x^n = x^(n/2) * x^(n/2)
 * n为奇数 x^n = x^(n/2) * x^(n/2) * x
 * */

#include<iostream>

class Solution{
public:
	double myPow(double base, int exponent){
		double res = 1.0;
		int i = exponent;
		while(i){
			if(i & 1) res *= base;
			base *= base;
			i /= 2;
		}
		return exponent < 0 ? 1.0 / res : res;
	}
};


int main(){
	Solution s;
	std::cout << s.myPow(2.0, -4);
	return 0;
}

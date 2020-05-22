/*
 * 圆圈中最后剩下的数字
 *
 * 0,1,,n-1这n个数字排成一个圆圈,从0开始,每次从这个圆圈里删除第m个数字。
 * 求出这个圆圈里剩下的最后一个数字。
 *
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字,
 * 则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 *
 * */


/* 思路一：借助list
 *
 * 使用list模拟环形链表，当指针指向end时，移至begin即可
 *
 * */

class Solution1{
public:
	int lastRemaining(int n, int m){
		list<int> nums;
		for(int i = 0; i < n; i++) nums.push_back(i);
		auto it = nums.begin();
		int ret = *it;
		while(nums.size()){
			for(int i = 1; i < m; i++){
				++it;
				if(it == nums.end()) it = nums.begin();
			}
			ret = *it;
			it = nums.erase(it);  // list删除节点后，返回后一节点的iterator
			if(it == nums.end()) it = num.begin();
		}
		return ret;
	}
};


/* 思路二：约瑟夫问题
 * 
 * N个人围成一圈，第一个人从1开始报数，报M的将被杀掉，
 * 下一个人接着从1开始报。如此反复，最后剩下一个，求最后的胜利者。
 *
 * f(n,m)=[f(n−1,m)+m]%n
 *
 * */

class Solution2{
public:
	int lastRemaning(int n, int m){
		int last = 0;
		for(int i = 2; i <= n; i++)
			last = (last + m) % i;
		return last;
	}
};

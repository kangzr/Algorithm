/*
 * 旋转数组的最小数字
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 *
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 *
 * 思路：二分法，考虑numbers[mid] == numbers[right] 情况
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	int minArray(vector<int>& numbers)
	{
		if (numbers.size() == 0) return -1;
		int left = 0, right = numbers.size() - 1, mid = 0;
		while(left < right){
			mid = (left + right) / 2;
			if(numbers[mid] == numbers[right])
				right--;
			else if(numbers[mid] < numbers[right])
				right = mid;
			else
				left = mid + 1;
		}
		return numbers[left];
	}

};


int main()
{
	Solution s;
	vector<int> nums = {1,1,1,0,1};
	int res = s.minArray(nums);
	cout << res << endl;
	return 0;
}

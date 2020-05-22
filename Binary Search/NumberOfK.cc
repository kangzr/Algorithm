/*
 * 数字在排序数组中出现的次数
 *
 * 统计一个数字在排序数组中出现的次数。例如:
 *
 * 输入: [1,2,3,3,4,5] 和 3，
 * 输出: 2
 *
 * */


/* 思路: upperbound  lowerbound
 * upperbound找到第一个大于target的数的索引idx1
 * lowerbound找到第一个大于等于target的数的索引idx2
 * count = idx1 - idx2
 * */

#include <vector>
#include <iostream>
using namespace std;


class Solution{
public:
	int my_lower_bound(vector<int> &nums, int target){
		int low = 0, high = nums.size();
		while(low < high){
			int mid = low + (high - low) / 2;
			if(nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		return  low;
	}

	int my_upper_bound(vector<int> &nums, int target){
		int low = 0, high = nums.size();
		while(low < high){
			int mid = low + (high - low) / 2;
			if (nums[mid] <= target)
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}

	int numberOfK(vector<int> &nums, int k){
		// int low = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
		// int upper = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
		int low = my_lower_bound(nums, k);
		int upper = my_upper_bound(nums, k);
		return upper - low;
	}
};

int main()
{
	Solution s;
	vector<int> nums = {1,2,3,3,3,3,4,5};
	int res = s.numberOfK(nums, 3);
	cout << res << endl;
	return 0;
}

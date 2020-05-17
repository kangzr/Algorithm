/*
 * 数组中的逆序对
 *
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，
 * 则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 *
 * */


/* 思路：归并排序
 *
 * 归并排序采用分治思想，把数组一分为二，直到单个元素，然后再两两合并
 * 可以利用这一特性来顺便求逆序对，例如两个有有序对a [1,3,6,8], b [2,4,5]
 * a在左，b在右, 在合并的过程中, 若a[i] <= b[j] 则a[i]入有序数组，且i++,
 * 若a[i] > b[j], 则b[j]入有序数组，且b[j] < 所有a中尚存元素m,即+m个逆序对
 *
 * */

class Solution{
public:
	int cnt;
	void merge_sort(vector<int> &tmp, vector<int> &nums, int lo, int hi){
		if(lo >= hi) return;
		int mid = lo + (hi - lo) / 2;
		merge_sort(tmp, nums, lo, mid);
		merge_sort(tmp, nums, mid + 1, hi);
		int i = lo, j = mid + 1;
		for(int k = lo; k <= hi; k++){
			if(i > mid) tmp[k] = nums[j++];
			else if(j > hi) tmp[k] = nums[i++];
			else if(nums[i] > nums[j]){
				tmp[k] = nums[j++];
				cnt += mid - i + 1;
			}
			else tmp[k] = nums[i++];
		}
		copy(tmp.begin() + lo, tmp.begin() + hi + 1, nums.begin() + lo);
	}
	int reversePairs(vector<int> &nums){
		vector<int> tmp(nums.size(), 0);
		merge_sort(tmp, nums, 0, nums.size() - 1);
		return cnt;
	}
};

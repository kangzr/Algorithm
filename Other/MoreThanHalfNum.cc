/*
 * 数组中出现次数超过一半的数字
 *
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *
 * */

// 思路一：排序后，取中间数  时间复杂度O(nlogn)
class Solution1{
public:
	int majorityElem(vector<int>& nums){
		if(nums.empty()) return {};
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};


// 思路二：快排思想，取第n个最大数  时间复杂度O(n) 
// 最小的k个数也可以用这种方法
class Solution2{
public:
	int majorityElem(vector<int>& nums){
		if(nums.empty()) return {};
		int len = nums.size();
		int mid = len >> 1;
		int low = 0, high = len - 1;
		int idx = partition(nums, low, high);
		while(idx != mid){
			if(idx > mid)
				high = idx - 1;
			else
				low = idx + 1;
		}
		return nums[mid];
	}

	int partition(vector<int>& nums, int low, int high){
		int pivot_key = nums[low];
		while(low < high){
			if(low < high && nums[high] >= pivot_key)
				high--;
			swap(nums[low], nums[high]);
			if(low < high && nums[low] <= pivot_key)
				low++;
			swap(nums[low], nums[high]);
		}
		return low;
	}
};


// 思路三：投票思想 遇到与自己相同的加1票 不同的减1票 票数为0时 更新值
// 时间复杂度O(n), 空间复杂度O(1)
class Solution3{
public:
	int majorityElem(vector<int>& nums){
		if(nums.empty()) return {};
		int majority, vote = 0;
		for(int i = 0; i < nums.size(); i++){
			if(vote == 0) majority = nums[i];
			if(majority == nums[i]) vote++;
			else vote--;
		}
		return majority;
	}
};

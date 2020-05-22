/*
 * 滑动窗口的最大值
 *
 * 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 *
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 *
 * */


/* 思路一：双端队列
 *
 * 维护一个双端队列，保存元素的索引值，
 * 队首永远为当前滑动窗口的最大值，每次循环把其加入结果
 *
 * */

class Solution1{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k){
		vector<int> res;
		if(nums.empty() || nums.size() < k)
			return res;
		deque<int> index;
		for(int i = 0; i < k; i++){
			while(index.size() && nums[i] > nums[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for(int i = k; i < nums.size(); i++){
			res.push_back(nums[index.front()]);
			while(index.size() && nums[i] > nums[index.back()])
				index.pop_back();
			// 如果队首元素不属于当前窗口，则pop
			if(index.size() && index.front() <= i - k)
				index.pop_front();
			index.push_back(i);
		}
		res.push_back(nums[index.front()]);
		return res;
	}
};


/*简化版*/

class Solution2{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k){
		vector<int> res;
		deque<int> index;
		for(int i = 0; i < nums.size(); i++){
			// 新元素入队时如果比队尾元素大的话就替代队尾元素
			while(index.size() && nums[i] > nums[index.back()])
				index.pop_back();
			//检查队首的index是否在窗口内，不在的话需要出队
			if(index.size() && index.front() <= i - k)
				index.pop_front();
		}
	}
};


/*
 * 队列的最大值
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，
 * 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 *
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 *
 * */


/*思路
 * 
 * 用一个deque维护队首最大值，插入新元素时，保证新元素不小于队尾元素
 *
 * */

class MaxQueue{
private:
	deque<int> max;
	queue<int> data;
public:
	MaxQueue(){}
	int max_value(){
		if(max.empty()) return -1;
		return max.front();
	}

	void push_back(int value){
		data.push(value);
		while(max.size() && value > max.back())
			max.pop_back();
		max.push_back(value);
	}

	int pop_front(){
		if(data.empty()) return -1;
		int ret = data.front();
		data.pop();
		if(max.size() && ret == max.front())
			max.pop_front();
		return ret;
	}
};

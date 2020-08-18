/*
 * 单调队列实现
 * 
 * */

/*
 * 单调递减
 * 底层结构: deque(双端队列), 队头尾删除和插入操作均为O(1)
 *
 * push(k)时判断，若k > queue.back()， 则queue.pop_back()删除队尾元素(压扁)
 * 直到遇到比k大元素，或者队列为空，保证从队头->队尾 单调递减
 *
 * pop(k): 如果queue.front() == k 则删除队头元素，否则，不操作(k已被压扁)
 *
 * */

class MonotonicQueue{
private:
	deque<int> data;
public:
	void push(int k){
		while(data.size() && k > data.back()){
			data.pop_back()
		}
		data.push_back(k);
	}

	void pop(int k){
		if(data.size() && k == data.front())
			data.pop_front();
	}
	int max(){
		return data.front();
	}
};



/* 应用1: Leetcode 239 滑动窗口最大值
 *
 * 给定一个数组nums,有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧
 * ,你只可以看到在滑动窗口内的k个数字。滑动窗口每次只向右移动一位。
 *
 * 返回滑动窗口中的最大值。
 *
 * */
class Solution{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k){
		vector<int> res;
		MonotonicQueue window;
		for(int i = 0; i < nums.size(); i++){
			if(i < k - 1){
				window.push(nums[i]);
			}else{
				window.push(nums[i]);
				res.push_back(window.max());
				window.pop(nums[i - k + 1]);
			}
		}
		return res;
	}
};

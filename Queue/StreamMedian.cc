/*
 * 数据流中的中位数
 *
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
 * 那么中位数就是所有数值排序之后位于中间的数值 如果从数据流中
 * 读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 *
 * 设计一个支持以下两种操作的数据结构：
 * 插入：void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * 获取：double findMedian() - 返回目前所有元素的中位数。
 *
 * 思路1: 未排序数组，插入时间复杂度O(1), 获取O(n)
 * 思路2: 排序数组，插入时间复杂度O(n), 获取O(1)
 * 思路3: 二叉搜索树，插入时间复杂度O(logn)/O(n), 获取O(logn)/O(n)
 * 思路4: AVL，插入时间复杂度O(logn), 获取O(1)
 * 思路5: 优先队列，插入时间复杂度O(logn), 获取O(1)
 *
 * */

// 优先队列解法
class  MedianFinder{
public:
	priority_queue<int> maxHeap;  // 左边大顶堆
	priority_queue<int, vector<int>, greater<int>> minHeap;  // 右边小顶堆
	MedianFinder(){}
	void addNum(int num){
		// 奇数放入左边
		if((maxHeap.size() + minHeap.size()) & 1){
			if(minHeap.size() && num > minHeap.top()){
				// 如果num比右边最小值大，则先入右边，再取出其top值放入左边
				minHeap.push(num);
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
			else maxHeap.push(num);
		}
		else{
			if(maxHeap.size() && num < maxHeap.top()){
				maxHeap.push(num);
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
			else minHeap.push(num);
		}
	}
	double findMedian(){
		if(minHeap.empty() && maxHeap.empty())
			return 0.0;
		if(((minHeap.size() + maxHeap.size()) & 1) == 0)
			return (minHeap.top() + maxHeap.top()) / 2.0;
		return minHeap.top() * 1.0;
	}
};

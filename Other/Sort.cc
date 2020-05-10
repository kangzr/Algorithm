/*排序算法*/


/*快排
 *
 * 基本思想：选一个关键字，通过一趟排序，小于关键字的数据放其左侧，
 * 比关键字大的放其右侧，在分别对左右两部分进行排序
 *
 * 平均时间复杂度：O(nlogn), 最坏时间复杂度(关键字为极值): O(n^2)
 *
 * */
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high){
	// int mid = (high + low) / 2;
	int pivot_key = vec[low];  // 这里可以优化，三数取中
	while(low < high){
		while(low < high && vec[high] >= pivot_key)
			high--;
		swap(vec[low], vec[high]);
		while(low < high && vec[low] <= pivot_key)
			low++;
		swap(vec[low], vec[high]);
	}
	return low;
}

void quick_sort_core(vector<int>& vec, int low, int high){
	int pivot;
	if(low < high){
		int pivot = partition(vec, low, high);
		cout << "pivot" << pivot << endl;
		quick_sort_core(vec, low, pivot);
		quick_sort_core(vec, pivot + 1, high);
	}
}

void quick_sort(vector<int>& vec){
	quick_sort_core(vec, 0, vec.size() - 1);
}


int main(){
	vector<int> vec = {8,3,4,6,2};
	quick_sort(vec);
	for(auto v : vec)
		cout << v << ", ";
	return 0;
}


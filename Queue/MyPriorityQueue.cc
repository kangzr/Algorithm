/*优先队列(大顶堆, 小顶堆)
*/
class PriorityQueue{
private:
	vector<int> vec;
	int N = 0;
public:
	PriorityQueue(int cap){
		vec = vector<int>(cap+1, 0);
	}
	int Max(){
		return vec[1];
	}
	// 父节点
	int parent(int root){
		return root / 2;
	}

	// left
	int left(int root){
		return root * 2;
	}

	// right
	int right(int root){
		return root * 2 + 1;
	}
	
	// 上浮
	void swim(int k){
		while(k > 1 && vec[parent(k)] < vec[k]){
			// k大于其父节点, k上浮
			swap(vec[parent[k]], vec[k]);
			k = parent(k);
		}
	}

	// 下沉
	void sink(int k){
		// 到底就不再沉
		while(vec[left(k) <= N]){
			//假设左边节点较大
			int older = left(k);
			// 比较右节点
			if(right(k) <= N && vec[older] < vec[right(k)])
				older = right(k);
			// 结点k比俩孩子都大, 就不必下沉
			if(vec[older] < vec[k]) break;
			// 否则，k下沉
			swap(vec[older], vec[k]);
			k = older;
		}
	}

	// 插入
	void insert(int val){
		N++;
		vec.push_back(val);
		swim(N);
	}	

	// 删除
	int delMax(){
		int max = vec[1];
		swap(vec[1], vec.back());
		vec.pop_back();
		sink(1);
		return max;
	}
};


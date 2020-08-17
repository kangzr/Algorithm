/*
 * LRU缓存机制 (最近最少使用机制) Least Recently Used
 *
 * 获取数据get(key) : key在缓存中，则获取关键字的值(>0)，否则返回-1 
 * 写入数据put(key, val): key存在，则变更其值为val，否则，插入。当缓存容量达到上限，在写入数据之前删除最久未使用的数据，为新数据留出空间.
 *
 * 要求get/put时间复杂度均为O(1)
 *
 * */

/* 思路:
 *
 * 1. get要满足O(1), 考虑使用hash table : unordered_map
 *
 * 2. put/delete满足O(1), 考虑list
 *
 * unordered_map：<K: key, V: iterator --> list中val所在的位置>
 *
 * list: <pair<int, int>(p1, p2)>, p1: key, pe: value
 *
 * get:如果key存在map中,根据对应的iterator返回value，并把list中k/v移至头部
 *     否则返回-1;
 *
 * put: 如果key存在map中，则修改list中对应的value，并移至头部，
 * 否则，判断list是否超容量，如果超了，删除最后一个key/value, 最后插入新值
 *
 * */

class LRUCache{
public:
	LRUCache(int capacity){
		_cap = capacity;
	}

	int get(int key){
		const auto& it = _m.find(key);
		if(it == _m.end()) return -1;
		// k/v 移至头部
		_cache.splice(_cache.begin(), _cache, it->second);
		return it->second->second;
	}

	void put(int key, int val){
		const auto& it = _m.find(key);
		if(it != _m.end()){
			it->second->second = val;
			// k/v 移至头部
			_cache.splice(_cache.begin(), _cache, it->second);
			return;
		}
		if (_cache.size() >= _cap){
			_m.pop(_cache.back().first);
			_cache.pop_back();
		}
		// 插入首部
		_cache.emplace_front(make_pair(key, val));
		_m[k] = _cache.begin();
	}

private:
	int _cap;
	list<<pair<int, int>> _cache;
	unorderd_map<int, list<pair<int, int>::iterator> _m;
};

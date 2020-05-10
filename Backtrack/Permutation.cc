/*
 * 字符串的排列
 *
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 *
 * 
 * */

/* 思路一  交换+回溯
 * 将字符串分为两部分，每次固定一个字符为一部分，剩下的为另一部分，
 * 然后将固定字符与其他字符进行交换，依次遍历每个字符
 *
 * 用set去重
 *
 * */


class Solution{
public:
	set<string> s;
	vector<string> permutation(string s){
		backtrace(s, 0);
		return vector<string>(s.begin(), s.end());
	}

	void backtrace(string s, int cursor){
		if(cursor == s.size()){
			s.insert(s);
			return;
		}
		for(int i = cursor; i < s.size(); i++){
			swap(s[i], s[cursor]);
			backtrace(s, cursor + 1);
			swap(s[i], s[cursor]);
		}
	}
};


/*STL库函数next_permutation*/
class Solution1{
public:
	vector<string> permutation(string s){
		if(s.empty()) return {};
		sort(s.begin(), s.end());
		vector<string> res;
		res.emplace_back(s);
		while(next_permutation(s.begin(), s.end()))
			res.emplace_back(s);
		return res;
	}
};

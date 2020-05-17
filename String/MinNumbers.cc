/*
 * 把数组排成最小的数
 *
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 *
 * */

// 选取使字符串组合更小的排序规则
//
class Solution{
public:
	string minNumbers(vector<int>& nums){
		vector<string> strs;
		for(auto n : nums)
			strs.push_back(to_string(n));
		sort(strs.begin(), strs.end(), [](string &s1, string &s2){return s1 + s2 < s2 + s1;});
		string ans;
		for(auto s : strs)
			ans += s;
		return ans;
	}
};

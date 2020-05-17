/*
 * 最长不含重复字符的子字符串
 *
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 *
 * */


/* 思路1: 双指针
 *
 * 左指针left 右指针right
 *
 * 从左指针起寻找右指针指向的值s[right], 若得到的idx < right，则重复
 * 令left=idx+1, 否则，right指针继续行走
 *
 * */

class Solution1{
public:
	int lengthOfLongestSubstring(string s){
		if(s.size() < 2) return s.size();
		int left = 0, right = 1, maxLen = 1;
		while(right < s.size()){
			while(true){
				int dupIdx = s.find(s[right], left);
				if(dupIdx == right) break;
				left = dupIdx + 1;
			}
			right++;
			maxLen = max(maxLen, right-left);
		}
		return maxLen;
	}
};


/* 思路2:
 *
 * 开辟128个数组大小，用于记录字符的索引值
 *
 * */

class Solution2{
public:
	int lengthOfLongestSustring(string s){
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for(int i = 0; i < s.size(); i++){
			left = max(m[s[i]], left);
			m[s[i]] = i;
			res = max(res, right - left);
		}
		return res;
	}
};

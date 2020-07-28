/*
 * 栈的压入、弹出序列
 * 
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
 * 例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
 * 序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
 * 但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 *
 * */

/* 思路：使用stack
 * 如果栈顶元素等于popped序列中下一个要pop的值，则应立刻将该值 pop 出来。
 * */

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> stk;
    	int idx1 = 0, idx2 = 0;
    	while(idx1 < pushed.size()){
		    stk.push(pushed[idx1++]);   
		    while(idx2 < popped.size() && stk.size() && (stk.top() == popped[idx2])){
				stk.pop();
				idx2++;
			}
		}
    	return stk.empty();
    }
};

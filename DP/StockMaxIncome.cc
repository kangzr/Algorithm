/*
 * 股票的最大利润
 *
 * 假设把某股票的价格按照时间先后顺序存储在数组中，
 * 请问买卖该股票一次可能获得的最大利润是多少？
 *
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 *
 * */


/* 思路：
 *
 * 记录到第i天为止，前i - 1天中股票最低价
 * 选择最低价买入，第i天卖出，记录第i天的收益，并更新最大收益和最低价格
 *
 * */

class Solution{
	public:
		int stockMaxIncome(vector<int> &prices){
			if(prices.empty()) return 0;
			int minPrice = prices[0];
			int maxIncome = 0;
			for(int i = 1; i < prices; i++){
				maxIncome = max(maxIncome, prices[i] - minPrice);
				minPrice = min(minPrice, prices[i]);
			}
			return maxIncome;
		}
};

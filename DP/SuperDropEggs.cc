/*
 * 高楼扔鸡蛋
 *
 * N层楼，k个鸡蛋(K > 0), 求F(0<=F<=N)楼层，在这层楼扔鸡蛋不会碎.
 * 问最坏情况下，至少要扔几次鸡蛋，才能确定楼层F
 *
 * */


/* 思路
 *
 * 状态含义dp[K][N]: K个鸡蛋，N层楼，最优结果
 *
 * 状态转移(考虑没碎和碎两种情况)
 *
 * dp[K][N] = max(dp[K, N - i], dp[K - 1, i - 1]) + 1
 *
 * 时间复杂度：O(K * N ^ 2)  空间复杂度: O(KN)
 * */

// pair作为unordered_map的key

struct pair_hash{
	template<class T1, class T2>
	std::size_t operator() {const std::pair<T1, T2>& p} const{
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
}


class Solution{
public:
	unordered_map<pair<int, int>, int, pair_hash> memo;
	int res = INT_MIN;
	int superDropEggs(int K, int N){
		dp(K, N);
		return memo[make_pair(K, N)];
	}
	int dp(int K, int N){
		if(K == 1) return N;
		if(N == 0) return 0;
		if(memo.count(make_pair(K, N))) 
			return memo[make_pair(K, N)];
		for(int i = 1; i <= N; i++)
			// dp(K, N-i)没碎   dp(K-1, i-1)碎了 max(最坏) +1(第i楼扔楼一次)
			res = min(res, max(dp(K, N-i), dp(K-1,i-1)) + 1);
		memo[make_pair(K, N)] = res;
		return res;
	}
};


/* 思路：二分
 *
 * 时间复杂度 O(K * N * logN)
 *
 * */


class Solution{
public:
	unordered_map<pair<int, int>, int, pair_hash> memo;
	int superDropEggs(int K, int N){
		dp(K, N);
		return memo[make_pair(K, N)];
	}
	int dp(int K, int N){
		if(K == 1) return N;
		if(N == 0) return 0;
		if(memo.count(make_pair(K, N))) 
			return memo[make_pair(K, N)];
		int res = INT_MIN;
		int lo = 1, hi = N;
		while(lo <= hi){
			mid = lo + (hi - lo) / 2;
			int broken = dp(K-1, mid-1);
			int not_broken = dp(K, N - mid);
			if(broken > not_broken){
				hi = mid - 1;
				res = min(res, broken + 1);
			}
			else{
				lo = mid + 1;
				res = mid(res, not_broken + 1);
			}
		}
		memo[make_pair(K, N)] = res;
		return res;
	}
};


/* 思路：状态转移方程优化
 *
 * 把问题转化为K个鸡蛋，测试m次，最坏情况最多能测试N层楼
 *
 * dp[K][m]: 即为K个鸡蛋，测试m次，最多测试几层楼
 *
 * dp[K][m] = dp[K-1][m-1] + dp[K][m-1] + 1
 *
 * 时间复杂度: O(KN) 空间复杂度: O(KN)
 *
 * */

class Solution{
public:
	int superDropEggs(int K, int N){
		vector<int, vector<int>> dp(K, vector<int>(N, 0));
		m = 0;
		while(dp[K][m] < N){
			m++;
			for(int k = 1; k <= K; k++)
				dp[K][m] = dp[K-1][m-1] + dp[K][m-1] + 1;
		}
		return m;
	}
};

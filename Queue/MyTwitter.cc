/*
 * Twitter设计
 *
 * */

class Twitter{
	int timestamp = 0;

	class Tweet{

	}

	class User{

	}

	// user 发一条tweet
	void postTweet(int userId, int tweetId){

	}

	// 返回user关注的人(包括自己) 最近的tweet id, 最多10条，按时间排序
	vector<int> getNewsFeed(int userId){

	}

	// follower 关注 followee, Id不存在则新建？
	void follow(int followerId, int followeeId){

	}

	// follower取消关注followee, Id不存在则忽略
	void unfollow(int followerId, int followeeId){

	}
};

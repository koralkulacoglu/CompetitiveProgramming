class Twitter {
    int feedSize;
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>> followers;
public:
    Twitter() {
        feedSize = 10;
        timestamp = 0;
        for (int i=1; i<=500; i++) followers[i].insert(i);
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int>& follows = followers[userId];
        priority_queue<pair<int, int>> news;

        for (int follow : follows) {
            auto& tweetList = tweets[follow];
            int n = tweetList.size();
            int endIndex = max(0, n - feedSize);

            for (int i=n-1; i>=endIndex; i--) {
                news.push(tweetList[i]);
            }
        }

        vector<int> res;
        while (!news.empty() && res.size() < feedSize) {
            res.push_back(news.top().second);
            news.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

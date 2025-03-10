class Twitter {
public:
    struct Compare{
        bool operator()(const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b){
            return a.second.second < b.second.second;
        }
    };
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({tweetId, time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, Compare> pq;

        for(auto it = tweetMap[userId].begin(); it!= tweetMap[userId].end(); it++){
            pq.push({it->first, {userId, it->second}});
        }

        if (followMap.find(userId) != followMap.end()) {
            for (auto followedUserId : followMap[userId]) {
                for (auto tweet : tweetMap[followedUserId]) {
                    pq.push({tweet.first, {followedUserId, tweet.second}});
                }
            }
        }

        vector<int>feed;
        while(!pq.empty() && feed.size() < 10){
            feed.push_back(pq.top().first);
            pq.pop();
        }

        return feed;  
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
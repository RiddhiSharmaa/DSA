class Twitter {
public:
    int count = 0;
    unordered_map<int, vector<pair<int, int>>>mpp;
    unordered_map<int, unordered_set<int>>fol;
    
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        mpp[userId].push_back({count, tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;

        for (auto& [timeStamp, tweetId] : mpp[userId]){
            pq.push({timeStamp, tweetId});
        }

        for (auto& followerId : fol[userId]){
            for (auto& [timeStamp, tweetId] : mpp[followerId]){
                pq.push({timeStamp, tweetId});
            }
        }

        vector<int>newsFeed;
        int cnt = 0;

        while (cnt < 10 && !pq.empty()){
            int tweet = pq.top().second;
            pq.pop();
            newsFeed.push_back(tweet);
            cnt++;
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
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
#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    int timeStamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> {time, tweetId}
    unordered_map<int, unordered_set<int>> follows;    // user -> followees
public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> feed;
        follows[userId].insert(userId); // include self
        for (int u : follows[userId])
        {
            for (auto &t : tweets[u])
                feed.push_back(t);
        }
        sort(feed.begin(), feed.end(),greater<>());
        vector<int> res;
        for (int i = 0; i < min(10, (int)feed.size()); ++i)
            res.push_back(feed[i].second);
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};

int main()
{

}
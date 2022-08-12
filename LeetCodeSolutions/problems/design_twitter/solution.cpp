class Twitter
{
public:
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    usersPosts.push_back({userId, tweetId});
  }

  std::vector<int> getNewsFeed(int userId)
  {
    int tweets = 10;
    std::vector<int> feedTweetsResult;

    // Loop Recent Tweets
    for (int post = usersPosts.size() - 1; post >= 0; post--)
    {
      if (tweets == 0)
        break;

      int feedUsersId = usersPosts[post].first;
      int feedTweetsId = usersPosts[post].second;

      std::unordered_set<int> userFollows = userFollow[userId];

      // Add Post only if user follow second user or from themself
      if (userFollows.find(feedUsersId) != userFollows.end() || feedUsersId == userId)
      {
        feedTweetsResult.push_back(feedTweetsId);
        tweets--;
      }
    }
    return feedTweetsResult;
  }

  void follow(int followerId, int followeeId)
  {
    userFollow[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    userFollow[followerId].erase(followeeId);
  }

private:
  // Tracks user followees
  std::unordered_map<int, std::unordered_set<int>> userFollow;

  // Tracks usersid and their posts
  std::vector<std::pair<int, int>> usersPosts;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
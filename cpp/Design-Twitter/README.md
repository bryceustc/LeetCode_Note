# 题目描述:  设计推特

设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

- postTweet(userId, tweetId): 创建一条新的推文
- getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
- follow(followerId, followeeId): 关注一个用户
- unfollow(followerId, followeeId): 取消关注一个用户

**示例 :**
```
Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);
```

# 解题思路:

  哈希表+优先队列

# 时间复杂度：
  O(1)
# 空间复杂度
O(1)
  
# 代码

### 
```c++
class Twitter { 
public:
    unordered_map<int,unordered_set<int>> userId2follow;
    unordered_map<int,vector<pair<int,int>>> userId2Tweet;
    int timeStamp;//时间戳
    Twitter() {
        timeStamp=0;//时间戳初始化
    }
    
    void postTweet(int userId, int tweetId) {
        /*添加推特，记得++timeStamp*/
        userId2Tweet[userId].push_back({timeStamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        priority_queue<pair<int, int>> q; // 默认大顶堆 可以自定义cmp，pair的话是默认比较第一个元素
        // 将用户自身ID加入，方便后边读取推文
        userId2follow[userId].insert(userId);
        for (int i : userId2follow[userId])
        {
            // i为用户所关注人的id
            for (pair<int,int> & p : userId2Tweet[i])
            {
                // p为关注人i所发布的推文
                q.push(p);
            }
        }
        // 根据优先队列排序将最近的10条推文加入结果中
        while(!q.empty()&&res.size()<10)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userId2follow[followerId].insert(followeeId);//关注
    }
    
    void unfollow(int followerId, int followeeId) {
        userId2follow[followerId].erase(followeeId);//取关
    }
};
```

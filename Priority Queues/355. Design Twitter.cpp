class Twitter {
    private:
    int timer = 0;
        class tweet
        {
            public:
            int ID;
            int time;
            tweet* next;

            tweet(int id, int timee)
            {
                ID = id;
                time = timee;
                next = NULL;
            }
        };

        class user
        {
            public:
            int ID;
            tweet* head;
            unordered_set<int> followSet;

            user(int ID)
            {
                this->ID = ID;
                followSet.insert(ID);
                head = NULL;
            }

            void follow(int id)
            {
                followSet.insert(id);
            }

            void unFollow(int id)
            {
                followSet.erase(id);
            }

            void post(int id, int timee)
            {
                tweet *t = new tweet(id, timee);
                t->next = head;
                head = t;
            }
        };

        unordered_map<int, user*> users;
    public:
    Twitter() 
    {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(users.find(userId) == users.end())
        {
            user* u = new user(userId);
            users[userId] = u;
        }

        users[userId]->post(tweetId, ++timer);
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        if(users.find(userId) == users.end())
        {
            return {};
        }
        vector<int> retFeed;

        priority_queue<pair<int, int>> feed;

        unordered_set<int> ffs = users[userId]->followSet;

        for(int i : ffs)
        {
            tweet *t = users[i]->head;
            while(t != NULL)
            {
                feed.push({t->time, t->ID});
                t = t->next;
            }
        }

        int n = 0;
        while(!feed.empty() && n < 10)
        {
            retFeed.push_back(feed.top().second);
            feed.pop();
            n++;
        }

        return retFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(users.find(followerId) == users.end())
        {
            user* u = new user(followerId);
            users[followerId] = u;
        }
        if(users.find(followeeId) == users.end())
        {
            user* u = new user(followeeId);
            users[followeeId] = u;
        }
        users[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId) == users.end())
        {
            user* u = new user(followerId);
            users[followerId] = u;
        }
        if(users.find(followeeId) == users.end())
        {
            user* u = new user(followeeId);
            users[followeeId] = u;
        }
        users[followerId]->unFollow(followeeId);
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

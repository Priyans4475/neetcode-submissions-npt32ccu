class Twitter {
public:
    Twitter() {
        
    }
    unordered_map<int,map<int,int>>mp;
    unordered_map<int,map<int,int>>f;
    int cnt;
    void postTweet(int userId, int tweetId) {
        mp[userId][tweetId]=cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it:mp[userId])
        {
            pq.push({it.second,it.first});
        }
        for(auto it:f[userId])
        {
            for(auto i:mp[it.first])
        {
            pq.push({i.second,i.first});
        }

        }

        int k=10;
        vector<int>ans;
        while(!pq.empty() && k--)
        {
            auto it=pq.top();
            cout<<it.first<<" "<<endl;
          ans.push_back(it.second);
          pq.pop();
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        f[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
         if(followerId!=followeeId)
        f[followerId].erase(followeeId);
    }
};

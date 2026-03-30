class LRUCache {
public:
int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;
    
        auto it=mp[key];

        dll.erase(it);
        dll.push_front({key,it->second});

        return it->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            dll.erase(it);

        }
        else
        {
            if(mp.size()==cap)
            {
                auto it=dll.back();
                dll.pop_back();
                mp.erase(it.first);
            }
        }
        dll.push_front({key,value});
        mp[key]=dll.begin();
    }
};

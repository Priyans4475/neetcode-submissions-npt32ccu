class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       auto &it=mp[key];
       string ans="";
       int l=0;
       int r=it.size()-1;
       while(l<=r)
       {
        int mid=(l+r)/2;

        if(it[mid].first<=timestamp)
        {
            ans=it[mid].second;
            l=mid+1;
        }
        else
        r=mid-1;
       }
       return ans;


    }
};

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
        int low=0;
        int high=it.size()-1;
        string ans="";
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(it[mid].first<=timestamp)
            {
                   ans= it[mid].second;
                   low=mid+1;
              
            }
            else if(it[mid].first > timestamp)
            {
                high=mid-1;
            }
          
             
        }
        return ans;

    }
};
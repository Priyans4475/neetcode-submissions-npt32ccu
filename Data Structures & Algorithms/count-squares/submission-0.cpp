class CountSquares {
public:
    map<pair<int,int>,int>mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
       int x=point[0];
        int y=point[1];
        
        mp[{x,y}]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
         int ans=0;
        for(auto &i:mp)
        {
            auto it=i.first;
            int a=it.first;
            int b=it.second;


            if( a!=x && abs(a-x)==abs(b-y))
            {
                pair<int,int>temp1={a,y};
                pair<int,int>temp2={x,b};

                if(mp.find(temp1)!=mp.end() && mp.find(temp2)!=mp.end())
                {
                    ans+= i.second*mp[{a,y}]*mp[{x,b}];
                }
            }
            


        }
        return ans;
    }
};

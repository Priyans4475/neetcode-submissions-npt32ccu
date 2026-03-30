class Solution {
public:
    int carFleet(int tar, vector<int>& p, vector<int>& sp) {
       int n=p.size();
     vector<pair<int,double>>temp;
     
       for(int i=0;i<n;i++)
       {
        double time=(double)(tar-p[i])/sp[i];
        temp.push_back({p[i],time});
       }
 sort(temp.begin(),temp.end(),[](auto &a,auto &b)
       {
        return a.first>b.first;
       });

       stack<double>s;
       for(auto &it:temp)
        {

        if(!s.empty() && it.second<=s.top())
        {
            continue;
        }
        s.push(it.second);
       }

       return s.size();
    }
};

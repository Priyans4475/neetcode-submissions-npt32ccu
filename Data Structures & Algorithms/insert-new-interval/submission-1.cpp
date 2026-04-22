class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<vector<int>>res;
        for(auto it:intervals)
        {
            ans.push_back(it);
        }
        ans.push_back(newInterval);

        sort(ans.begin(),ans.end());
       int st1=ans[0][0];
       int end1=ans[0][1];
       for(auto i=1;i<ans.size();i++)
        {
             int st2=ans[i][0];
             int end2=ans[i][1];

             if(end1>=st2 )
             {
                st1=st1;
                if(end1<end2)
                end1=end2;
             }
             else
             {
                res.push_back({st1,end1});
                st1=st2;
                end1=end2;
                
             }

        }
        res.push_back({st1,end1});

        return res;
    }
};

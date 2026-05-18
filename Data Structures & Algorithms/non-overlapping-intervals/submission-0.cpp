class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[]( const vector<int>&a, const vector<int>&b)
        {
            return a[1]<b[1];
        });

        int first=intervals[0][0];
        int sec=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<sec)
            {
            ans++;
            }
            else
            {
                sec=intervals[i][1];
            }
        }

        return ans;
    }
};

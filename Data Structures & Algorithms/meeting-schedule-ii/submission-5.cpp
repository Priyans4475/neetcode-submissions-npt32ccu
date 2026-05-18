/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         int n=intervals.size();
         if(n==0)
         return 0;

       map<int,int>mp;

       for(int i=0;i<n;i++)
       {

        mp[intervals[i].start]++;
        mp[intervals[i].end]--;

       }

       int maxi=0;
       int overlap=0;
       for(auto it:mp)
       {

        overlap+=it.second;
        maxi=max(maxi,overlap);
        
       }

       return maxi;
    }
};

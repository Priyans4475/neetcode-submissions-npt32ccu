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
    bool canAttendMeetings(vector<Interval>& intervals) {
         int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[]( const Interval&a, const Interval&b)
        {
            return a.start<b.start;
        });

        int first=intervals[0].start;
        int sec=intervals[0].end;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i].start<sec)
            {
            return false;
            }
            else
            {
                sec=intervals[i].end;
            }
        }

        return true;
    }
};

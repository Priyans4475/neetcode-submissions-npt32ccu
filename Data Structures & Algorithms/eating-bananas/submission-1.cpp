class Solution {
public:
    int help(vector<int>& piles, int h,int mid)
    {
        long long ans=0;
        int n=piles.size();
        
        for(int i=0;i<n;i++)
       {
        ans+= ceil((double)piles[i]/mid);
       }
      
       if(ans<=h)
       return 1;
       else
       return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1;
       int high=INT_MIN;
       int res=0;
       int n=piles.size();
       for(int i=0;i<n;i++)
       {
        low=min(low,piles[i]);
        high=max(high,piles[i]);
       } 
       while(low<=high)
       {
        int mid=(low+high)/2;
        if(help(piles,h,mid))
        {
            high=mid-1;
            res=mid;
        }
        else
           low=mid+1;
       }
       return res;
    }
};

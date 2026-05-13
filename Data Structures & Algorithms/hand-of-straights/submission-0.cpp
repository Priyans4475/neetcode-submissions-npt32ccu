class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n=hand.size();
       int x=groupSize;
       sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
         mp[hand[i]]++;
       }

      for(int i=0;i<n;i++)
       {
         
         if(mp.find(hand[i])!=mp.end())
         {
            for(int j=0;j<x;j++)
            {
                if(mp.find(hand[i]+j)!=mp.end())
                {
                    mp[hand[i]+j]--;
                }
                else 
                return false;


                if(mp[hand[i]+j]==0)
                mp.erase(hand[i]+j);
            }
            
         }

         
       }

       return true;
       
        
    }
};

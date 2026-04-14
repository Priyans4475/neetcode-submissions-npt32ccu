class Solution {
public:
     int help(int ind,vector<int>&coins,int tar,vector<vector<int>>&dp)
    {   
        if(tar<0)
        return 0;
        if(tar==0)
        return 1;
        if(ind==0)
        {
            if(tar%coins[ind]==0)
            return 1;
            else
            return 0;
        }
        if(dp[ind][tar]!=-1)
        return dp[ind][tar];

        int take=0;
       if(tar>=coins[ind])
        {    take=help(ind,coins,tar-coins[ind],dp);
            
           
          }
        int nottake=0;
        if(ind-1>=0)
        nottake=help(ind-1,coins,tar,dp);

        return dp[ind][tar]= take + nottake;
    }
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=help(n-1,coins,amount,dp);
        
        if(ans==INT_MAX)
        return 0;
        else
        return ans;
    }
};


class Solution {
public:
    int help(int ind,vector<int>&coins,int tar,vector<vector<int>>&dp)
    {   
        if(tar<0)
        return INT_MAX;
        if(tar==0)
        return 0;
        if(ind==0)
        {
            if(tar%coins[ind]==0)
            return tar/coins[ind];
            else
            return INT_MAX;
        }
        if(dp[ind][tar]!=INT_MAX)
        return dp[ind][tar];

        int take=INT_MAX;
       if(tar>=coins[ind])
        {   int res=help(ind,coins,tar-coins[ind],dp);
            if(res!=INT_MAX)
            take=1+res;
            else
            take=res;}
        int nottake=INT_MAX;
        if(ind-1>=0)
        nottake=help(ind-1,coins,tar,dp);

        return dp[ind][tar]= min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        int ans=help(n-1,coins,amount,dp);
        
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};

class Solution {
public:
   int help(int ind,vector<int>&prices,int buy,vector<vector<int>>&dp)
   {
    if(ind>=prices.size())
    return 0;
    if(dp[ind][buy]!=-1)
    return dp[ind][buy];

    if(buy)
    {
        return dp[ind][buy]=max(-prices[ind]+help(ind+1,prices,0,dp),help(ind+1,prices,1,dp));
    }

    return dp[ind][buy]=max(prices[ind]+help(ind+2,prices,1,dp),help(ind+1,prices,0,dp));

   }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(0,prices,1,dp);
    }
};

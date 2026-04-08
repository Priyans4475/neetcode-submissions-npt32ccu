class Solution {
public:
    int help(int i,vector<int>&cost,vector<int>&dp)
    {
        if(i==0 || i==1)
        return cost[i];
        if(dp[i]!=-1)
        return dp[i];

       return dp[i]=cost[i]+min(help(i-1,cost,dp),help(i-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1)
        return cost[0];
        
        vector<int>dp(n,-1);
        return min(help(n-1,cost,dp),help(n-2,cost,dp));

    }
};

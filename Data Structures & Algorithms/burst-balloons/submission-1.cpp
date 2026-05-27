class Solution {
public:
    int help(int i,int j, vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        return 0;

        int max_coin=INT_MIN;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int k=i;k<=j;k++)
        {

            int coins=nums[i-1]*nums[k]*nums[j+1];

            int rem= help(i,k-1,nums,dp)+help(k+1,j,nums,dp);

            max_coin=max(max_coin,coins+rem);

        }

        return dp[i][j]=max_coin;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return help(1,n,nums,dp);
    }
};

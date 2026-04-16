class Solution {
public:
    int help(int ind,int last,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind][last+1]!=-1)
        return dp[ind][last+1];
        int take=0;
        if( nums[ind]>nums[last] || last==-1)
        {
            take= 1+help(ind+1,ind,nums,dp);
        }
        int nottake=help(ind+1,last,nums,dp);

        return dp[ind][last+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int last=-1;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return help(0,last,nums,dp);
    }
};

class Solution {
public:
    int help(int i,vector<int>&dp,vector<int>nums)
    {
        if(i==1)
        return max(nums[i],nums[0]);

        if(i==0)
        return nums[0];

        if(dp[i]!=-1)
        return dp[i];

        int take=nums[i]+help(i-2,dp,nums);
        int nottake=help(i-1,dp,nums);

        return dp[i]=max(take,nottake);

        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return help(n-1,dp,nums);

    }
};

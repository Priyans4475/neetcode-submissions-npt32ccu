class Solution {
public:
    bool help(int ind,int tar,vector<int>nums, vector<vector<int>>&dp)
    {
        if(tar<0)
        return false;
        if(tar==0)
        return true;
        if(dp[ind][tar]!=-1)
        return dp[ind][tar];
        if(ind==nums.size()-1)
        {
            if(tar==nums[ind])
            return true;
            else
            return false;
        }

        int nottake=help(ind+1,tar,nums,dp);
        int take=0;
        if(tar>=nums[ind])
        take=help(ind+1,tar-nums[ind],nums,dp);

        return dp[ind][tar]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++)
        {
            tot+=nums[i];
        }
        if(tot%2!=0)return false;
        int tar=tot/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return help(0,tot/2,nums,dp);
    }
};

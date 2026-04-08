class Solution {
public:
    int help(int i,vector<int>&dp,vector<int>nums)
    {
      
        if(i==1)
        return max(nums[1],nums[0]);

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
        if(n==1)
        return nums[0];
        vector<int>dp1(n+1,-1);
         vector<int>dp2(n+1,-1);
        vector<int>nums1(n-1);
        vector<int>nums2(n-1);
        for(int i=0;i<n-1;i++)
        {
            nums1[i]=nums[i];
        }

        for(int i=1;i<n;i++)
        {
            nums2[i-1]=nums[i];
        }
        return max(help(n-2,dp1,nums1),help(n-2,dp2,nums2));

    }
};

class Solution {
public:
    int findways(int ind,int target,vector<int>&nums)
    {
        
        if(ind==0)
         {
            if(target==0 && nums[ind]==0)
            return 2;
            if(target==nums[ind] || target==0)
            {
                return 1;
            }
            
            else
            return 0;
         }

         int nottake=findways(ind-1,target,nums);
         int take=0;
         if(nums[ind]<=target)
         {
            take=findways(ind-1,target-nums[ind],nums);
         }
         return take+nottake;


    }
    int countpartition(int n, int target,vector<int>&nums)
    {
        int totsum=0;
        for(int i=0;i<n;i++)
        {
            totsum+=nums[i];

        }

        if((totsum-target)<0 || (totsum-target)%2)
        return false;


        return findways(n-1,(totsum-target)/2,nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countpartition(n,target,nums);
    }
};

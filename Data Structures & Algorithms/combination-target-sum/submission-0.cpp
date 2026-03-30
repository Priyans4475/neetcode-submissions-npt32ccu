class Solution {
public:
   vector<vector<int>> res;
   void help(int ind,vector<int>&nums,int target,vector<int>&ans)
   {
    if(ind>=nums.size()){
    if(target==0)
    {
        res.push_back(ans);
        return;

    }
    return;
    
    }
    if(target<0)
    return;

    ans.push_back(nums[ind]);
    help(ind,nums,target-nums[ind],ans);
    ans.pop_back();
    help(ind+1,nums,target,ans);
   }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ans;
        help(0,nums,target,ans);
        return res;
    }
};

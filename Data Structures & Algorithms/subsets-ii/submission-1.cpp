class Solution {
public:
    vector<vector<int>>res;
    void help(int ind,vector<int>&nums,vector<int>&ans)
    {
        res.push_back(ans);

        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
            continue;

            ans.push_back(nums[i]);
            help(i+1,nums,ans);
            ans.pop_back();
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        help(0,nums,ans);
      return res;

    }
};

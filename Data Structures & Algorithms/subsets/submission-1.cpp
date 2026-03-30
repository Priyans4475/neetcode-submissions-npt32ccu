class Solution {
public:
    vector<vector<int>> help(int ind,vector<int>&nums,vector<int>&ans,vector<vector<int>>&res)
    {
        if(ind>=nums.size())
        {
            res.push_back(ans);
            return res;
        }

        ans.push_back(nums[ind]);
        help(ind+1,nums,ans,res);

        ans.pop_back();
        help(ind+1,nums,ans,res);


        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>res;
       return help(0,nums,ans,res);
    }
};

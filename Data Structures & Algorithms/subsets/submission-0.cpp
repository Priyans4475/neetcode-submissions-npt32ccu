class Solution {
public:
 vector<vector<int>>res;
    void help(int ind,vector<int>&nums,vector<int>&ans)
    {
        if(ind>=nums.size())
        {
            res.push_back(ans);
           return;
        }

        ans.push_back(nums[ind]);
        help(ind+1,nums,ans);

        ans.pop_back();
        help(ind+1,nums,ans);

       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
       
       help(0,nums,ans);
       return res;
    }
};

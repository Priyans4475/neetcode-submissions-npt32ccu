class Solution {
public:
    vector<vector<int>>res;

    void help(vector<int>&nums,unordered_map<int,int>&mp,vector<int>&ans)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!mp[i])
            {
                mp[i]=1;
                ans.push_back(nums[i]);
help(nums,mp,ans);
mp[i]=0;
ans.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        help(nums,mp,ans);
        return res;
    }
};

class Solution {
public:
    set<vector<int>>res;
    void help(int ind,vector<int>&nums,vector<int>&ans)
    {
        if(ind==nums.size())
        {
            res.insert(ans);
            return;
        }
       
        ans.push_back(nums[ind]);
        help(ind+1,nums,ans);
        ans.pop_back();
        help(ind+1,nums,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        help(0,nums,ans);
       vector<vector<int>>temp;
       for(auto it:res)
       {
        temp.push_back(it);
       }
       return temp;

    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int k=0;k<n;k++)
        {
            if(k>0 && nums[k]==nums[k-1])
            continue;
            int i=k+1;
            int j=n-1;
           int  target=-nums[k];
             while(i<j)
        {

            if(nums[i]+nums[j]==target)
            {res.push_back({nums[i],nums[j],nums[k]});

            i++;
            j--;

            if(i<j && nums[i]==nums[i-1])
            i++;
            if(i<j && nums[j]==nums[j+1])
            j--;
            }
            else if(nums[i]+nums[j]<target)
            {
                i++;
            }
            else
            j--;

        }
       

        }
        return res;
    }
};

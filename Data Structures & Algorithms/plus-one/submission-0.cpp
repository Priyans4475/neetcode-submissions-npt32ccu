class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<9)
            {
                nums[i]+=1;
                break;
            }
            else
            {
                nums[i]=0;
               
            }
        }
        if(nums[0]==0)
        {
            ans.push_back(1);
        }

        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;

    }
};

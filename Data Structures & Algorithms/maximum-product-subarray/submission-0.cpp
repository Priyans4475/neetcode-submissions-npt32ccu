class Solution {
public:
    int maxi=INT_MIN;
    void help(int ind,vector<int>nums,int size)
    {
        if(ind==size)
        {
            return;
        }

        int mult=1;
        for(int i=ind;i<size;i++)
        {
            mult*=nums[i];
            maxi=max(mult,maxi);
        }
        help(ind+1,nums,size);
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        help(0,nums,n);
        return maxi;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int jump=nums[0];
        int i=0;
        while(i<n)
        {
            if(i<=jump)
            {
                jump=max(jump,i+nums[i]);
            }
           i++;
           if(jump>=n-1)
           return true;
        }
        return false;
    }
};

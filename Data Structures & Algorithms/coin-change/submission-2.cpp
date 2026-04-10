class Solution {
public:
    int help(int ind,vector<int>&coins,int tar)
    {   
        if(tar<0)
        return INT_MAX;
        if(tar==0)
        return 0;
        if(ind==0)
        {
            if(tar%coins[ind]==0)
            return tar/coins[ind];
            else
            return INT_MAX;
        }
        int take=INT_MAX;
       if(tar>=coins[ind])
        {if(help(ind,coins,tar-coins[ind])!=INT_MAX)
            take=1+help(ind,coins,tar-coins[ind]);
            else
            take=help(ind,coins,tar-coins[ind]);}
        int nottake=INT_MAX;
        if(ind-1>=0)
        nottake=help(ind-1,coins,tar);

        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int ans=help(n-1,coins,amount);
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};

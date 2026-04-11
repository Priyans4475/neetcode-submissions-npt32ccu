class Solution {
public:
    bool help(int ind,int size,string &s,set<string>&st,vector<int>&dp)
    {
        if(ind==size)
        return 1;

        if(dp[ind]!=-1)
        return dp[ind];

        string temp;
        for(int i=ind;i<size;i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                if(help(i+1,size,s,st,dp))
                   return dp[ind]=1;
            }
        }
        return dp[ind]=0;
       

    }
    bool wordBreak(string s, vector<string>& words) {
       
        set<string>st;
        int n=s.length();
        vector<int>dp(n,-1);
        for(auto it:words)
        {
            st.insert(it);
        }
        return help(0,n,s,st,dp);
    }
};

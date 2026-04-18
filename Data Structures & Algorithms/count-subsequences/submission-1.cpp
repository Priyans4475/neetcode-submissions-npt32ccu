class Solution {
public:
    int help(int i,int j,string s, string t,vector<vector<int>>&dp)
    {
        int cnt=0;
        if(j==t.length())
        {
            return 1;
        }
        if(i==s.length())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int take=0;
         int nottake=help(i+1,j,s,t,dp);
        if(s[i]==t[j])
        {
            take=help(i+1,j+1,s,t,dp);
        }
       

        return dp[i][j]=take+nottake;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(0,0,s,t,dp);
    }
};

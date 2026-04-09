class Solution {
public:
    
    int pal(string s)
    {
        if(s.length()==0)
        return false;
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]!=s[s.length()-i-1])
            return false;

        }
        return true;
    }
    int help(int ind,string s,vector<int>&dp)
    {
       
      int cnt=0;
      
      if(ind==s.length())
      return 0;
     if(dp[ind]!=-1)
     return dp[ind];
      for(int i=ind;i<s.length();i++)
      {
        string temp=s.substr(ind,i-ind+1);
        
        if(pal(temp))
        cnt++;

      }
     return dp[ind]=cnt+help(ind+1,s,dp);
      
    }
    int countSubstrings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        string temp="";
       return help(0,s,dp);

      
    }
};

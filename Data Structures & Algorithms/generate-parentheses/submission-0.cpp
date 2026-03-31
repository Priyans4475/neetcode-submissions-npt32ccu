class Solution {
public:
   vector<string>res;
   void help(int open,int closed,string s,int n)
   {
    if(open==n && closed==n)
    {
        res.push_back(s);
        return;
    }
    if(open<n)
    {
        help(open+1,closed,s+"(",n);
    }
    if(closed<open && closed<n)
    {
        help(open,closed+1,s+")",n);
    }
   }
    vector<string> generateParenthesis(int n) {
        string s="";
       help(0,0,s,n);
       return res;
    }
};

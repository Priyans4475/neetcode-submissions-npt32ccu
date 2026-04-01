class Solution {
public:
   
   vector<string>res;
    void help(int ind,string &digits,string &ans,unordered_map<int,string>&mp)
    {
        if(ind>=digits.length())
        {
            res.push_back(ans);

            return;
        }
          string temp=mp[digits[ind]-'0'];
          for(int i=0;i<temp.length();i++)
          {
            ans.push_back(temp[i]);
            help(ind+1,digits,ans,mp);
            ans.pop_back();
          }
        
    }
    vector<string> letterCombinations(string digits) {
        
         unordered_map<int,string>mp;
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";
       
        string ans;
        if(digits.length()==0)
        return res;
        help(0,digits,ans,mp);
        return res;
    }
};

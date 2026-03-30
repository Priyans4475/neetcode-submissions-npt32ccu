class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
             for(int i=0;i<strs.size();i++)
             {
                string x=to_string(strs[i].length());
                s+=x+'#'+strs[i];
             }
             return s;
    }

    vector<string> decode(string s) {
           vector<string>ans;
           string temp="";
           int i=0;
        while(i<s.length())
        {
            int j=i;
            while(s[j]!='#')
            j++;

            int len=stoi(s.substr(i,j-i));
            j++;

            ans.push_back(s.substr(j,len));
            i=j+len;
            
        }
           return ans;
    }
};

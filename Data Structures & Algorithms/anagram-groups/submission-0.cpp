class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        vector<string>temp;
        for(int i=0;i<n;i++)
        {
            map<char,int>mp1;
            for(int k=0;k<strs[i].length();k++)
            {
                mp1[strs[i][k]]++;
            }
            for(int j=i;j<n;j++)
            {
                
                map<char,int>mp2;
                if(strs[j]=="0")
                continue;
             for(int k=0;k<strs[j].length();k++)
            {
                mp2[strs[j][k]]++;
            }
            if(mp1==mp2)
            {temp.push_back(strs[j]);
            strs[j]="0";
            }

            }
            if(temp.size()>0)
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

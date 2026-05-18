class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last=0;
        int n=s.length();

        int j=0;
        vector<int>res;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            int x=s[i];
            if(mp.find(s[i])!=mp.end())
            {
                continue;
            }
            else
            {
                int ans=0;
                for(int i=0;i<n;i++)
                {
                    if(x==s[i])
                    {
                        ans=i;
                    }
                }
                mp[x]=ans;
            }

        }
        for(int i=0;i<n;i++)
        {
            if(last<mp[s[i]])
            {
                last=mp[s[i]];
            }

            if(i==last)
            {
               res.push_back(last-j+1);
               j=last+1;
            }


        }

        return res;
    }
};

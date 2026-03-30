class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int i=0;
        int j=0;
        int max_freq=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            max_freq=max(max_freq,mp[s[i]]);

            if((i-j+1)-max_freq>k)
            {
                mp[s[j]]--;
                j++;
            }

            res=max(res,(i-j+1));

        }
        return res;
    }
};

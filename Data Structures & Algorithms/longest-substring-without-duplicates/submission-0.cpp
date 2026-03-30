class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
           for(int j=i;j<n;j++)
           {
            st.insert(s[j]);
            if(st.size()!=(j-i+1))
            break;
           }
           ans=max(ans,(int)st.size());
           st.clear();
        }
        return ans;

    }
};

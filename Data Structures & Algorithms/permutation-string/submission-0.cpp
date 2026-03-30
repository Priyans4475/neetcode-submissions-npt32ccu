class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>m1,m2;
        int n=s1.length();
        int m=s2.length();
        for(auto i : s1)
        m1[i]++;

        for(int i=0;i<n;i++)
        {
            m2[s2[i]]++;

        }
        if(m1==m2)
        return true;
    
        for(int i=n;i<m;i++)
        {
            m2[s2[i-n]]--;
            if(m2[s2[i-n]]==0)
            m2.erase(s2[i-n]);
            m2[s2[i]]++;
            if(m1==m2)
             return true;
            
             cout<<endl;
        }
        return false;
    }
};

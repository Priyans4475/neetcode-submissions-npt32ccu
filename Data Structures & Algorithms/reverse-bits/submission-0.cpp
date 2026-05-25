class Solution {
public:
    uint32_t reverseBits(uint32_t n) {


        string s;

        while(n>0)
        {
            s+=to_string(n%2);
            n=n/2;

        }

        for(int i=s.length();i<32;i++)
        {
            s+='0';
        }
        

        uint32_t ans=0;
       cout<<s;
        reverse(s.begin(),s.end());

        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='1')
           {
            ans+=pow(2,i);
           }
        }

        return ans;
        
    }
};

class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int>mp;
        int num=n;
        while(1)
        {
            int temp=0;
            
            while(num)
            {
                int rem=num%10;
                temp+=rem*rem;
                num/=10;
            }
            cout<<temp<<endl;
            if(temp==1)
            return true;
           
            if(mp.find(temp)!=mp.end())
             break;
            num=temp;
             mp[temp]++;
        }

        return false;
    }
};

class Solution {
public:
    int reverse(int x) {
        int n=x;
        int ans=0;
        int neg=0;
        // if(n<0)
        // {neg=1;
        // n=n*-1;}

        // if(n>(pow(2,31)-1) || n<(-1*(pow(2,31))))
        // return 0;
        
        while(n!=0)
        {
           int res=n%10;
            
            n=n/10;
            // overflow check
            if (ans > INT_MAX / 10 || 
               (ans == INT_MAX / 10 && res > 7))
                return 0;

            // underflow check
            if (ans < INT_MIN / 10 || 
               (ans == INT_MIN / 10 && res < -8))
                return 0;
            ans=ans*10+res;
        }
       
        // if(neg)
        // return ans*-1;
        // else
        return ans;
    }
};

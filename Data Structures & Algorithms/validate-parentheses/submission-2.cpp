class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int i=0;
        int n=s.length();
        while(i<n)
         {   if( !st.empty() && s[i]==']')
            {
              if(st.top()!='[' )  
              return false;
              else
              st.pop();
            }
            else if(!st.empty() && s[i]=='}' )
            {
                if(st.top()!='{' )
                return false;
                else
                st.pop();
            }
            else if( !st.empty() && s[i]==')' )
            {
                if(st.top()!='(' )
                return false;
                else
                st.pop();
            }
           
            else
            st.push(s[i]);

            i++;
         }
         if(st.empty())
         return true;
         else
         return false;
    }
};

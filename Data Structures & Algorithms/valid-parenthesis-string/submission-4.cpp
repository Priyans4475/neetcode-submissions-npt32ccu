class Solution {
public:
    bool checkValidString(string s) {
        int cnt=0;
        stack<int>st;
        stack<int>stk;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(')
          {
            st.push(i);
          }
          else if(s[i]==')')
          {
            if(!st.empty())
            {
                st.pop();
            }
            else 
            { if(!stk.empty())
            {
                stk.pop();
            }
            else
            return false;
                
            }
          }
          else 
          
          stk.push(i);
        }

       while(!st.empty() && !stk.empty())
       {
        if(stk.top()>st.top())
        {
            stk.pop();
            st.pop();
        }
        else 
        return false;
       }
        if(st.empty() )
        return true;
       else
        return false;
    }
};

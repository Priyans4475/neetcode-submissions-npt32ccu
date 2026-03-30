class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>s;
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            if(t[i]=="+")
            {
              int t1=s.top();
              s.pop();
              int t2=s.top();
              s.pop();
              int t3=t1+t2;
              s.push(t3);
            }
            else if(t[i]=="-")
            {
            int t1=s.top();
              s.pop();
              int t2=s.top();
              s.pop();
              int t3=t2-t1;
              s.push(t3);
            }
            else if(t[i]=="*")
            {
             int t1=s.top();
              s.pop();
              int t2=s.top();
              s.pop();
              int t3=t1*t2;
              s.push(t3);
            }
            else if(t[i]=="/")
            {
               int t1=s.top();
              s.pop();
              int t2=s.top();
              s.pop();
              int t3=t2/t1;
              s.push(t3); 
            }
            else
            {
                s.push(stoi(t[i]));
            }
        }
       return s.top();
    }
};

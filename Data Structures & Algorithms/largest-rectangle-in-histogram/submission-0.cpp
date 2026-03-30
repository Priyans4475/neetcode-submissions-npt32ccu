class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         int n = arr.size();
         int maxArea=0;
         vector<int>ls(n); 
         vector<int>rs(n);
         stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }

            if(s.empty())
            {
              ls[i]=0;
            }
            else
            {
                ls[i]=s.top()+1;
            }
           s.push(i);
           cout<<ls[i]<<" ";
        }
        cout<<endl;
        while(!s.empty())
        {
            s.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }

            if(s.empty())
            {
              rs[i]=n-1;
            }
            else
            {
                rs[i]=s.top()-1;
            }
           s.push(i);
           cout<<rs[i]<<" ";
        }
        cout<<endl;
         int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
           res=max(res,arr[i]*(rs[i]-ls[i]+1));
        }


    return res;
    }
};
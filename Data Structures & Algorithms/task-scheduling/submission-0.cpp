class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto i:tasks)
        {
            mp[i]++;
        }

        priority_queue<int>pq;
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        int cnt=0;
        while(!pq.empty())
        { 
           
            int cycle=n+1;
            vector<int>temp;
            while(cycle && !pq.empty())
            {
                int x=pq.top();
            pq.pop();
            if(x>1)
            {
                temp.push_back(x-1);
            }

            cycle--;
            cnt++;
            }

            for(auto i:temp)
            {
                pq.push(i);
            }

            if(pq.empty())
            break;

            cnt+=cycle;
        }

        return cnt;
    }
};

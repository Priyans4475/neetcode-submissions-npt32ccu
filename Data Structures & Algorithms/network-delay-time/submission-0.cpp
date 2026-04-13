class Solution {
public:
    typedef pair<int,int>pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<vector<pii>>adj(n+1);
        vector<int>distance(n+1,INT_MAX);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        distance[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int node=it.second;
            // if(dist>distance[node])
            // continue;
            for(auto it:adj[node])
            {
               int v=it.first;
               int d=it.second;
               if(distance[node]+d<distance[v])
               {
                distance[v]=distance[node]+d;
                pq.push({distance[v],v});
               }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            maxi=max(distance[i],maxi);
        }
        if(maxi==INT_MAX)
        return -1;
        else
        return maxi;

        

    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indeg(numCourses);
        for(int i=0;i<adj.size();i++){
        for(auto it:adj[i])
        {
            indeg[it]++;
        }
        }

        queue<int>q;
       for(int i=0;i<numCourses;i++)
       {
        if(indeg[i]==0)
        q.push(i);
       }

       int cnt=0;
       vector<int>ans;
       while(!q.empty())
       {
        int x=q.front();
        q.pop();
        ans.push_back(x);
        cnt++;
        for(auto it:adj[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            q.push(it);
        }

       }
       if(cnt==numCourses)
       return ans;
       else
       return {};

    }
};

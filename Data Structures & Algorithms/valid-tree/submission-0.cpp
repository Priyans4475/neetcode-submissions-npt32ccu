class Solution {
public:
    bool dfs(int node, int parent,vector<int>&visited,vector<vector<int>>adj)
    {
      visited[node]=1;

      for(auto it:adj[node])
      {
        if(!visited[it])
        {
            if(!dfs(it,node,visited,adj))
        return false;}

        else if(parent!=it)
        return false;
        
        
      }
      return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
       
        if(!dfs(0,-1,visited,adj))
        return false;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            return false;
        }
        return true;
           
           

       
    }
};

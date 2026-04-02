class Solution {
public:
   
    int r [4] = {-1,0,1,0};
    int c [4] = {0,1,0,-1};
    int maxi=0;
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int cnt,int row,int col)
    {
         int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            row=it.first;
            col=it.second;

          for(int i=0;i<=3;i++)
        {
            int nrow=row+r[i];
            int ncol=col+c[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
            {
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
                cnt++;
            }
        }
        }
        maxi=max(maxi,cnt);

        



    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    bfs(grid,visited,1,i,j);
                }
            }
        }

        return maxi;
    }
};

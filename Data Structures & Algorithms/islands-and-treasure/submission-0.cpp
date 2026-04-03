class Solution {
public:
    int r [4] = {-1,0,1,0};
    int c [4] = {0,1,0,-1};
    
    void bfs(vector<vector<int>>& grid)
    {
         int n=grid.size();
        int m=grid[0].size();
        
        
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                 q.push({0,{i,j}});
            }
        }

        

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int cnt=it.first;
            auto it2=it.second;
            int row=it2.first;
            int col=it2.second;

          for(int i=0;i<=3;i++)
        {
            int nrow=row+r[i];
            int ncol=col+c[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m  && grid[nrow][ncol]!=-1 &&  grid[nrow][ncol]>cnt+1)
            {
                grid[nrow][ncol]=cnt+1;
                q.push({cnt+1,{nrow,ncol}});
               
            }
        }
        }
    }  

        
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
};

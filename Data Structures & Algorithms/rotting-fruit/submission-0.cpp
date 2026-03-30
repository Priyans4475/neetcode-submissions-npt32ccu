class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({{i,j},0});
            }
        }
        int time=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            auto cod=it.first;
            time=it.second;
            int r=cod.first;
            int c=cod.second;

            for(int i=0;i<4;i++)
            {
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];

                if(nr>=0 && nr<n && nc>=0 && nc<m  && grid[nr][nc]==1)
                {
                    cout<<nr<<" "<<nc<<endl;
                    grid[nr][nc]=2;
                    q.push({{nr,nc},time+1});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {return -1;
                break;}
            }
        }
        return time;
    }
};

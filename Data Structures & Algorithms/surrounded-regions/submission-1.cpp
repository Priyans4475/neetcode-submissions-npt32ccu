class Solution {
public:
    int r[4]={-1,0,1,0};
    int c[4]={0,1,0,-1};
    void dfs(vector<vector<char>>& board,int row,int col, vector<vector<int>> &vis)
    {
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
           for(int i=0;i<4;i++)
           {
              int nrow=r[i]+row;
              int ncol=c[i]+col;

              if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol])
              {
                 dfs(board,nrow,ncol,vis);
              }
           }
             
           
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
           
           
                if(board[i][0]=='O')
                {
                    dfs(board,i,0,vis);
                }

                if(board[i][m-1]=='O')
                dfs(board,i,m-1,vis);

              
          
        }
         for(int i=0;i<m;i++)
        {
           
           
            

                if(board[0][i]=='O')
                dfs(board,0,i,vis);

                if(board[n-1][i]=='O')
                dfs(board,n-1,i,vis);
          
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<vis[i][j]<<" ";
                if(vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
            cout<<endl;
        }

    }
};

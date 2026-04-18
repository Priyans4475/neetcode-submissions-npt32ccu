class Solution {
public:
    int r[4]={1,0,-1,0};
    int c[4]={0,-1,0,1};
    int dfs(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>& dp)
    {
        int best=1;
       if(dp[row][col]!=-1)
       return dp[row][col];
       for(int i=0;i<4;i++)
       {
        int nr=row+r[i];
        int nc=col+c[i];

       if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[row][col]<matrix[nr][nc])
       {
       
          
        best=max(best,1+dfs(nr,nc,n,m,matrix,dp));
       }
       }
       return dp[row][col]=best;

       

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                
                ans=max(ans,dfs(i,j,n,m,matrix,dp));
            }
        }

        return ans;
    }
};

class Solution {
public:
   bool isSafe(int row,int col,vector<string>board,int n)
   {
       int org_row=row;
       int org_col=col;

       while(row>=0 && col>=0)
       {
        if(board[row][col]=='Q')
        {
            return false;
        }
        row--;
        col--;
       }

       row=org_row;
       col=org_col;
       while(row<n && col>=0)
       {
        if(board[row][col]=='Q')
        {
            return false;
        }
        row++;
        col--;
       }
        row=org_row;
       col=org_col;
       while(col>=0)
       {
        if(board[row][col]=='Q')
        {
            return false;
        }
        col--;
       }

       return true;
   }
    void solve(int col,vector<string>&board,int n, vector<vector<string>>&ans)
    {
        if(n==col)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,n,ans);
            board[row][col]='.';}
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
           board[i]=s;
        }

        solve(0,board,n,ans);
        return ans;
    }
};

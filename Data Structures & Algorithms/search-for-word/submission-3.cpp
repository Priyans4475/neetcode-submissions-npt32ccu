class Solution {
public:
    int r[4] = {0, 1, 0, -1};
    int c[4] = {-1, 0, 1, 0};

    bool dfs(int row, int col, int ind, vector<vector<char>>& board, string &word) {
        int n = board.size();
        int m = board[0].size();

        if(ind == word.size()) return true;

        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[ind])
            return false;

        char ch = board[row][col];
        board[row][col] = '1';   // mark visited

        for(int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(dfs(nrow, ncol, ind + 1, board, word))
                return true;
        }

        board[row][col] = ch;    // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};
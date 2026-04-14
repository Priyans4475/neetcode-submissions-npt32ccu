class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        endOfWord = false;
        word = "";
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};

    void insert(string &word) {
        TrieNode* cur = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->endOfWord = true;
        cur->word = word;
    }

    void dfs(int row, int col, vector<vector<char>>& board, TrieNode* node, vector<string>& ans) {
        char ch = board[row][col];

        if(ch == '#' || node->children[ch - 'a'] == nullptr) return;

        node = node->children[ch - 'a'];

        if(node->endOfWord) {
            ans.push_back(node->word);
            node->endOfWord = false;   // avoid duplicates
        }

        board[row][col] = '#';

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                dfs(nrow, ncol, board, node, ans);
            }
        }

        board[row][col] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word : words) {
            insert(word);
        }

        vector<string> ans;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i, j, board, root, ans);
            }
        }

        return ans;
    }
};
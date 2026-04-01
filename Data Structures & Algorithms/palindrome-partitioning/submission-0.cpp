class Solution {
public:
    vector<vector<string>> res;

    bool ispalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void help(int ind, string &s, vector<string> &path) {
        if(ind == s.length()) {
            res.push_back(path);
            return;
        }

        for(int i = ind; i < s.length(); i++) {
            if(ispalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                help(i + 1, s, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        help(0, s, path);
        return res;
    }
};
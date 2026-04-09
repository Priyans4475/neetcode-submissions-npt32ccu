class Solution {
public:
    int help(int i, string &s, vector<int> &dp) {
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int one = help(i + 1, s, dp);
        int two = 0;

        if(i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26) {
                two = help(i + 2, s, dp);
            }
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return help(0, s, dp);
    }
};
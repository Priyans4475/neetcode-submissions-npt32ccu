class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.length();
        int m = s.length();

        if (n > m) return "";

        vector<int> arr1(128, 0);
        vector<int> arr2(128, 0);

        for (char c : t)
            arr1[c]++;

        string ans = "";
        int prevlen = INT_MAX;

        for (int i = 0; i < m; i++) {
            fill(arr2.begin(), arr2.end(), 0);
            int cnt = 0;
            string temp = "";

            for (int j = i; j < m; j++) {
                arr2[s[j]]++;
                temp += s[j];

                if (arr2[s[j]] <= arr1[s[j]])
                    cnt++;

                if (cnt == n) {
                    if (temp.length() < prevlen) {
                        prevlen = temp.length();
                        ans = temp;
                    }
                    break;  // smallest for this i
                }
            }
        }
        return ans;
    }
};



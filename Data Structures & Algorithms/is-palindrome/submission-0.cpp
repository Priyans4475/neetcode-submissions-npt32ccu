class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.length();
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            temp+=s[i];
        }

        int i=0;
        int j=temp.length()-1;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

        while(i<=j)
        {
            if(temp[i]!=temp[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};

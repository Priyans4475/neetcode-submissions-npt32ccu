class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(auto it:wordList)
        {
            st.insert(it);
        }

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int cnt=0;
        while(!q.empty())
        {

            auto it =q.front();
            string w=it.first;
            cnt=it.second;
            q.pop();
            if(w==endWord)
                {
                    return cnt;
                    break;
                }
            
            for(int i=0;i<w.length();i++)
            {
                int org=w[i];
                for(int j=0;j<26;j++)
            {
                w[i]='a'+j;

                

                if(st.find(w)!=st.end())
                {
                    q.push({w,cnt+1});
                    st.erase(w);
                }
                w[i]=org;
            }
            
            }


        }
        return 0;
    }
};

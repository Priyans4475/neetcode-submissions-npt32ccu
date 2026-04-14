class TrieNode{
    public:
    TrieNode* children[26];
    bool endofword;

    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;

        }
        endofword=false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    bool dfs(string word,int ind,TrieNode* root)
    {

         if(root==nullptr)
         return false;

        if(ind==word.size())
        {
            return root->endofword;
        }

        char c=word[ind];
        if(c=='.')
        {  for(int i=0;i<26;i++){
            if(root->children[i] && dfs(word,ind+1,root->children[i]))
            {
                return true;
            }}
            return false;
        }
        else
        {
             int i=c-'a';

             return dfs(word,ind+1,root->children[i]);

        }
        return false;
    }
    void addWord(string word) {
        TrieNode* cur=root;
        for(char c:word)
        {
            int i=c-'a';
            if(cur->children[i]==nullptr)
            {
                cur->children[i]=new TrieNode();
            }

            cur=cur->children[i];
        }
        cur->endofword=true;
    }
    
    bool search(string word) {
        //  TrieNode* cur=root;
        // for(char c:word)
        // {
        //     int i=c-'a';
        //     if(cur->children[i]==nullptr)
        //     {
        //         return false;
        //     }

        //     cur=cur->children[i];
        // }
        // return cur->endofword;

       return dfs(word,0,root);
    }
};

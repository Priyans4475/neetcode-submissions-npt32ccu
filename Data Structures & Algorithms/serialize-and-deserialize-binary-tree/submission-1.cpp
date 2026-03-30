/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    

    void dfs(TreeNode* root, string &s)
    {

        if(!root)
        {s+="N,";
        return;}


        s+=to_string(root->val);
        s+=',';

        
        dfs(root->left,s);
        
        dfs(root->right,s);

    }
    string serialize(TreeNode* root) {
       string s="";
        dfs(root,s);

        return s;
        
    }
    TreeNode* help(string data, int &ind)
    {
        if(data[ind]=='N')
        {ind+=2;
        return nullptr;}

        string temp="";
        while(data[ind]!=',')
        {
            temp+=data[ind++];
            
        }
        ind++;

        TreeNode* root=new TreeNode(stoi(temp));
        root->left=help(data,ind);
        root->right=help(data,ind);

        
      return root;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind=0;

        return help(data,ind);
        
    }
};

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

class Solution {
public:
    TreeNode* help(vector<int>&inorder,int si,int ei,vector<int>&preorder,int sp,int ep,map<int,int>&mp)
    {
        if(si>ei || sp>ep)
        return nullptr;

        int x=mp[preorder[sp]];
        int left=x-si;

        TreeNode* root=new TreeNode(preorder[sp]);
        root->left=help(inorder,si,x-1,preorder,sp+1,sp+left,mp);
        root->right=help(inorder,x+1,ei,preorder,sp+left+1,ep,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        map<int,int>mp;
       for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return help(inorder,0,n-1,preorder,0,n-1,mp);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   void dfs(Node* node,vector<int>&vis,unordered_map<int,vector<Node*>>&mp)
   {
    vis[node->val]=1;
    mp[node->val]=node->neighbors;

    for(auto it:node->neighbors)
    {
        if(vis[it->val]==0)
        dfs(it,vis,mp);
    }

   }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
        return node;
    unordered_map<int , vector<Node*>>mp;
    vector<int>vis(101,0);
    dfs(node,vis,mp);

    vector<Node*>temp(101);
    for(int i=0;i<101;i++)
    {
        temp[i]=new Node(i);
    }

    for(auto it:mp)
    {
        for(auto it1:it.second)
        {
            temp[it.first]->neighbors.push_back(temp[it1->val]);
        }
    }

    return temp[1];


    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      map<Node*,Node*>mp;
      Node* temp=head;
      while(temp)
      {
        Node* newnode=new Node(temp->val);
        mp[temp]=newnode;
        temp=temp->next;
      }

      temp=head;
      Node*clone=new Node(0);
      while(temp)
      {
        clone=mp[temp];
        clone->next=mp[temp->next];
        clone->random=mp[temp->random];
        temp=temp->next;
      }

      return mp[head];
    }
};

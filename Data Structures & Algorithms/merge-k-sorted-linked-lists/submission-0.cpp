/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val>b->val;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*,  vector<ListNode*>,compare> pq;

      for(auto it:lists)
      {
        if(it!=nullptr)
        pq.push(it);
      }
     ListNode* head=new ListNode(0);
     ListNode* temp=head;
      while(!pq.empty())
      {
        auto it=pq.top();
        pq.pop();

        head->next=it;
        head=head->next;

        if(it->next)
        pq.push(it->next);




      }

      return temp->next;
    }
};

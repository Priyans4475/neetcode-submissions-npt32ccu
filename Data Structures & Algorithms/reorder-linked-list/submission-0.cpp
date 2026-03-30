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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* l1=head;
        ListNode* l2=slow->next;
        slow->next=nullptr;

        ListNode* temp=l2;
        ListNode* prev=nullptr;

        while(temp)
        {
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;


        }
        l2=prev;

        while(l2)
        {
            ListNode* x=l1->next;
            ListNode* y=l2->next;

            l1->next=l2;
            l2->next=x;

            l1=x;
            l2=y;
        }
        

        




       



    }
};

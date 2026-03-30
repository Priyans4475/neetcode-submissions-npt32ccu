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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            cnt++;
        }

        int x=cnt-n;
        temp=head;
        if(x==0)
        return head->next;
        while(temp)
        {
            x--;
            if(x==0)
            {
                ListNode* forw=temp->next;
                temp->next=forw->next;
                break;
            }
            temp=temp->next;
            
        }
        return head;
        

    }
};

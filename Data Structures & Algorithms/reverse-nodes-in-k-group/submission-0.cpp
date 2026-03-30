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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int n=ans.size();
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        while((i+k-1)<n)
        {
         int a=i;
         int b=i+k-1;
         while(a<b)
         {
            swap(ans[a],ans[b]);
            a++;
            b--;
         }

         i=i+k;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* link=dummy;
        for(int i=0;i<n;i++)
        {
            link->next=new ListNode(ans[i]);
            link=link->next;
        }
        return dummy->next;
        

    }
};

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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==nullptr)
            return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode* ptr=head,*preptr=dummy,*temp=head,*x,*y;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        int k2=len-k+1;
        int pos=1;
        if(k==k2)
            return head;
        if(k>k2)
            swap(k,k2);
        while(ptr){
            if (k2-k==1 and pos==k){
                preptr->next=ptr->next;
                ptr->next=ptr->next->next;
                preptr->next->next=ptr;
                break;
            }
            if(pos==k){
                x=preptr;
                y=ptr;
            }
            if(pos==k2){
                x->next=ptr;
                ListNode* z=y->next;
                y->next=ptr->next;
                ptr->next=z;
                preptr->next=y;
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
            pos++;
            
        }
        return dummy->next;
    }
};
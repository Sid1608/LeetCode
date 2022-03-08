/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };  
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
                return NULL;
        ListNode *ptr,*preptr;
        ptr=head,preptr=head;
        while(ptr!=NULL){
            if(ptr->next==NULL)
                break;
            ptr=ptr->next->next;
            preptr=preptr->next;
            if(ptr==preptr)
                return true;
        }
        return false;
    }
};
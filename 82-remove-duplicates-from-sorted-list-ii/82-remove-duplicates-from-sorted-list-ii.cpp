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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode* newHead=new ListNode(0);
        ListNode* ptr=head,* preptr=newHead;
        ListNode* temp=ptr->next;
        while(ptr){
            int cnt=1;
            // cout<<ptr->val<<" "<<temp->val;
            while(temp and (ptr->val==temp->val)){
                temp=temp->next;
                cnt++;
            }
            if(cnt==1){
                preptr->next=ptr;
                preptr=ptr;
                ptr->next=nullptr;
                ptr=temp;
                if(temp)
                    temp=temp->next;
            }else{
                ptr=temp;
                if(ptr)
                    temp=ptr->next;
            }
        
        }
        return newHead->next;
    }
};
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
    ListNode* getMiddle(ListNode* head){

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* middle){
        ListNode* prev=NULL, *curr=middle,*next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode* prevMiddle=getMiddle(head);
        prevMiddle->next=reverseList(prevMiddle->next);
        // cout<<ptr->val;
        ListNode* ptr=head,*ptr1=prevMiddle->next;
        while(ptr1!=NULL){
            if(ptr->val!=ptr1->val){
                return false;
            }
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        prevMiddle->next=reverseList(prevMiddle->next);
         return true;
    }
    
   
    
};
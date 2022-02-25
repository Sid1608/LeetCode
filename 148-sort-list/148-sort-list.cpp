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

ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr,*ptr=nullptr;
        while(list1 and list2){
            if(list1->val<=list2->val){
                if(head==nullptr)
                    head=list1;
                if(ptr==nullptr)
                    ptr=list1;
                else{
                    ptr->next=list1;
                    ptr=ptr->next;
                }
                list1=list1->next;
            }else{
                if(head==nullptr)
                    head=list2;
                if(ptr==nullptr)
                    ptr=list2;
                else{
                    ptr->next=list2;
                    ptr=ptr->next;
                }
                list2=list2->next;
            }
        }
       
        while(list1){
            if(head==nullptr)
                    head=list1;
            if(ptr){
                ptr->next=list1;
                 ptr=ptr->next;
            }
            else
                ptr=list1;
            list1=list1->next;
          
        }
        while(list2){
            if(head==nullptr)
                    head=list2;
            if(ptr){
                ptr->next=list2;
                 ptr=ptr->next;
            }
            else
                ptr=list2;
            list2=list2->next;
    
        }
        if(ptr)
            ptr->next=nullptr;
        return head;
    }
ListNode* FindMiddle(ListNode* head){
    
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* mid=nullptr;
    while(fast and fast->next){
        mid=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    mid->next=nullptr;
    return slow;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
         if(head==nullptr)return head;
    if(head->next==nullptr)return head;
    
    ListNode* middle=FindMiddle(head);
    ListNode* list1=sortList(head);
    ListNode* list2=sortList(middle);
    ListNode* list=merge(list1,list2);
    return list;
    }
};
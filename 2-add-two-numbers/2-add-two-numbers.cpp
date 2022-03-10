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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        
        ListNode* head=new ListNode(0);
        ListNode* ptr=head;
        int carry=0,sum,val;
        while(list1 and list2){
            sum=list1->val+list2->val+carry;
            carry=sum/10,val=sum%10;
            ptr->next=new ListNode(val);
            ptr=ptr->next;
            list1=list1->next;
            list2=list2->next;
        }
        while(list1){
            sum=list1->val+carry;
            carry=sum/10;
            val=sum%10;
            ptr->next=new ListNode(val);
            ptr=ptr->next;
            list1=list1->next;

        }
         while(list2){
            sum=list2->val+carry;
            carry=sum/10;
            val=sum%10;
            ptr->next=new ListNode(val);
            ptr=ptr->next;
            list2=list2->next;
        }
        if(carry){
            ptr->next=new ListNode(carry);
            ptr=ptr->next;
        }
        return head->next;
    }
};
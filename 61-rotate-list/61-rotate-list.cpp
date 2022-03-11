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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)
            return head;
        ListNode* temp=head,*ans,*lastNode;
        int len=0;
        while(temp){
            len++;
            if(temp->next==nullptr){
                lastNode=temp;
                break;
            }
            temp=temp->next;
        }
        cout<<len;
        k=k%len;
        if(k==0)
            return head;
        temp=head;
        lastNode->next=head;
        int pos=0;
        while(temp){
            pos++;
            if(pos==len-k){
                ans=temp->next;
                temp->next=nullptr;
                break;
            }
            temp=temp->next;
        }
        return ans;
        
        
    }
};
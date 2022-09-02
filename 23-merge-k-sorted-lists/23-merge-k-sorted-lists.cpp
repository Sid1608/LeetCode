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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto node:lists){
            if(node)
               pq.push({node->val,node});
        }
        ListNode* head=NULL,*ptr;
        
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            if(head==NULL){
                head=node;
                ptr=node;
            }else{
                ptr->next=node;
                ptr=node;
            }
            if(node->next!=NULL){
                pq.push({node->next->val,node->next});
            }
        }
        return head;
    }
};
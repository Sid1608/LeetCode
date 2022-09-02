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
    
    ListNode* mergeLists(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        else if(l2==nullptr)return l1;
        
        ListNode* ans=new ListNode(-1);
        ListNode* ptr=ans;
        while(l1 and l2){
            if(l1->val<l2->val){
                ptr->next=l1;
                ptr=l1;
                l1=l1->next;
            }else{
                ptr->next=l2;
                ptr=l2;
                l2=l2->next;
            }
        }
        if(l1){
            ptr->next=l1;
        }
        if(l2){
            ptr->next=l2;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        for(int i=0;i<n-1;i++){
            lists[i+1]=mergeLists(lists[i],lists[i+1]);
        }
        return lists[n-1];
    }
    //using min heap
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//         priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
//         for(auto node:lists){
//             if(node)
//                pq.push({node->val,node});
//         }
//         ListNode* head=NULL,*ptr;
        
//         while(!pq.empty()){
//             ListNode* node=pq.top().second;
//             pq.pop();
//             if(head==NULL){
//                 head=node;
//                 ptr=node;
//             }else{
//                 ptr->next=node;
//                 ptr=node;
//             }
//             if(node->next!=NULL){
//                 pq.push({node->next->val,node->next});
//             }
//         }
//         return head;
    // }
};
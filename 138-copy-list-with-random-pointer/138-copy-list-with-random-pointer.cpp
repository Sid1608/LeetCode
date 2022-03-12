/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* newHead=new Node(0);
        Node* ptr=newHead,*node=head;
        //map node address with its position
        unordered_map<Node* ,int>q;
        //locate at current positon which locaion is present
        unordered_map<int,int>p;
        //gives nodes address at particular location in new list
        unordered_map<int,Node*>r;
        int pos=0;
        while(node){
            q[node]=pos;
            pos++;
            node=node->next;
        }
        q[nullptr]=-1;
        node=head;
        pos=0;
        while(node){
            Node* newNode=new Node(node->val);
            // newNode->random=head->random;
            p[pos]=q[node->random];
            ptr->next=newNode;
            r[pos]=newNode;
            ptr=ptr->next;
            node=node->next;
            pos++;
        }
        node=head,ptr=newHead->next;
        pos=0;
        r[-1]=nullptr;
        while(node){
            cout<<p[pos]<<" ";
            
            ptr->random=r[p[pos]];
            node=node->next;
             ptr=ptr->next;
            pos++;
        }
        return newHead->next;
        
            
        
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            while(sz--){
                Node* curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                for(Node* node: curr->children){
                    q.push(node);
                }
            }
            res.push_back(temp);
           
        }
        return res;
        
    }
};
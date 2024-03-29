/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>postorder;
//         if(root==NULL)
//             return postorder;
//         stack<TreeNode*>st1,st2;
        
//         st1.push(root);
//         while(!st1.empty()){
//             TreeNode* curr=st1.top();
//             st1.pop();
//             st2.push(curr);
//             if(curr->left)st1.push(curr->left);
//             if(curr->right)st1.push(curr->right);
//         }
//         while(!st2.empty()){
//             postorder.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return postorder;
//     }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root==NULL)
            return postorder;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(curr!=NULL or !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* node=st.top()->right;
                if(node==NULL){
                    node=st.top();
                    st.pop();
                    postorder.push_back(node->val);
                    while(!st.empty() and st.top()->right==node){
                        node=st.top();
                        postorder.push_back(node->val);
                        st.pop();
                    }
                    
                }else{
                    curr=node;
                }
            }
        }
        return postorder;
        
    }
};
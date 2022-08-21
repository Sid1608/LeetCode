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
    //Recurcive
    TreeNode* prev=NULL;
    void solve(TreeNode* root){
        if(!root)return ;
        solve(root->right);
        solve(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    TreeNode* getRightMostNode(TreeNode* leftNode){
        while(leftNode->right!=NULL){
            leftNode=leftNode->right;
        }
        return leftNode;
    }
    void flatten(TreeNode* root) {
        //iterative
        if(!root)return ;
        TreeNode* curr=root;
        stack<TreeNode*>st;
        st.push(curr);
        while(st.size()){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            // if(curr->left){
            //     ListNode* leftNode=curr->left;
            //     ListNode* rightMostNode=getRightMostNode(leftNode);
            //     rightMostNode->right=curr->right;
            // }
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=NULL;
            
        }
        
        
    }
};
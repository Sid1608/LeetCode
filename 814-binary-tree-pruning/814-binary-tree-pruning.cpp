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
    
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int flag=0,left=0,right=0;
        flag=root->val;
        if(root->right){
            right=solve(root->right);
            if(right==0){
                root->right=NULL;
            }
        }
        if(root->left){
            left=solve(root->left);
            if(left==0){
                root->left=NULL;
            }
        }
        
        return flag+left+right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(solve(root)==0)
            return NULL;
        return root;
    }
};
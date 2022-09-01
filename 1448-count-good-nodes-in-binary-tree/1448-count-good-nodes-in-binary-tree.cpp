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
    void count(TreeNode* root,int& res,int maxi){
        if(root==NULL)return;
        if(maxi<=root->val)res++;
        maxi=max(maxi,root->val);
        count(root->left,res,maxi);
        count(root->right,res,maxi);
    }
    int goodNodes(TreeNode* root) {
        int res=0;
        int maxi=INT_MIN;
         count(root,res,maxi);
        return res;
    }
};
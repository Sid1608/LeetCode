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
    int solve(TreeNode* root, int& global_maxi){
        if(root==NULL)return 0;
        
        int leftMaxPath=max(0,solve(root->left,global_maxi));
        int rightMaxPath=max(0,solve(root->right,global_maxi));
        
        global_maxi=max(global_maxi,root->val+leftMaxPath+rightMaxPath);
        
        return root->val+max(leftMaxPath,rightMaxPath);
        
    }
    int maxPathSum(TreeNode* root) {
        int global_maxi=-10000;
        int temp=solve(root,global_maxi);
        return global_maxi;
    }
};
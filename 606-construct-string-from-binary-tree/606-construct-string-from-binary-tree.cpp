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
    string solve(TreeNode* root){
        if(root==NULL){
            return "";
        }
        string res="";
        res+=to_string(root->val);
        string left=solve(root->left);
        string right=solve(root->right);
        if(left.size()||right.size()){
            res+="("+left+")";
            if(right.size()){
                res+="("+right+")";
            }
        }
        return res;
        
        
    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};
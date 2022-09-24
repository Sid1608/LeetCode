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
    void solve(TreeNode* root,int& t,vector<vector<int>>&ans,int currSum,vector<int>temp){
        
        if(root->left==NULL and root->right==NULL){
            if(currSum+root->val==t){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        if(root->left){
            temp.push_back(root->val);
            solve(root->left,t,ans,currSum+root->val,temp);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->val);
            solve(root->right,t,ans,currSum+root->val,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root)return ans;
        vector<int>temp;
        solve(root,targetSum,ans,0,temp);
        return ans;
    }
};
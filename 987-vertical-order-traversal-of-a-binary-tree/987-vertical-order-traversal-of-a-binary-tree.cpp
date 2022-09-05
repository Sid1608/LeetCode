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
    void solve(TreeNode* root,int r,int c,map<int,map<int,multiset<int>>>&mp){
        if(root==NULL)return;
        mp[c][r].insert(root->val);
        solve(root->left,r+1,c-1,mp);
        solve(root->right,r+1,c+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        solve(root,0,0,mp);
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>a;
            for(auto j:i.second){
                for(auto k:j.second){
                    a.push_back(k);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
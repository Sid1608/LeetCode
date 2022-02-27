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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            int mmin = q.front().second; 
            int l=INT_MAX,r=-1,cnt=0;
            while(sz--){
                pair<TreeNode*,int> curr=q.front();
                q.pop();
                if(curr.first){
                    l=min(l,curr.second);
                    r=max(r,curr.second);
                    if(curr.first->left)
                        q.push({curr.first->left,(long long)(curr.second-mmin)*2-1});
                    if(curr.first->right)
                        q.push({curr.first->right,(long long)(curr.second-mmin)*2});
                }
            }
            if(r!=-1 and l!=INT_MAX)
                res=max(res,r-l+1);
           
        }
        return res;
    }
};
class Solution {
public:
    void solve(int ind,vector<int>& nums,int n,set<vector<int>>&ans){
        
        if(ind==n){
            ans.insert(nums);
            return ;
        }
        
        for(int i=ind;i<n;i++){
            for(int j=i;j<n;j++){
                swap(nums[i],nums[j]);
                solve(ind+1,nums,n,ans);
                swap(nums[i],nums[j]);
            }
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>ans;
        solve(0,nums,n,ans);
        vector<vector<int>>res;
        for(auto v:ans){
           res.push_back(v);
        }
        return res;
    }
};
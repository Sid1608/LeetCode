class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            while(1<=nums[i]and nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if((long long) nums[i]-1!=i){
                ans=i+1;
                break;
            }
        }
        if(ans==-1)
            ans=n+1;
        return ans;
        
        return 0;
        
    }
};
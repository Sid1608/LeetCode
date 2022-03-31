class Solution {
public:
    bool isSplit(vector<int>&nums,int sum,int m){
        int cnt=0;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sum){
                return false;
            }
            if(currSum+nums[i]>sum){
                m--;
                currSum=nums[i];
            }else{
                currSum+=nums[i];
            }
        }

       return m>0;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int l=0,r=sum,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(isSplit(nums,mid,m)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
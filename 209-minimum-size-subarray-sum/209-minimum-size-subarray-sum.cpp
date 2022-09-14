class Solution {
public:
    //time complexity: o(n)
    //space complexity:o(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,res=INT_MAX,x=0;
        for(int r=0;r<n;r++){
            x+=nums[r];
            while(x>=target){
                res=min(res,r-l+1);
                x-=nums[l++];
            }
          
        }
        return res==INT_MAX?0:res;
    }
};
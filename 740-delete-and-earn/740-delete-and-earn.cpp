class Solution {
public:
    // 0 1 2 3 4 no
    // 0 0 1 1 1 cnt
    // 0 0 2 3 6 points
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int dp[10001]={0};
        for(int i=0;i<n;i++){
            dp[nums[i]]++;
        }
        int ans=dp[1];
        for(int i=2;i<10001;i++){
            //for each we have two option
            // 1. take i and i-2
            //2. take i-1
            dp[i]=max((dp[i]*i)+dp[i-2],dp[i-1]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
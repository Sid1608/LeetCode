class Solution {
public:
    int solve(int idx,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        
        if(idx==prices.size()||cap==0){
            return 0;
        }
        if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
        
        if(buy){
            return dp[idx][buy][cap]=max(-prices[idx]+solve(idx+1,0,cap,prices,dp),solve(idx+1,1,cap,prices,dp));
        }else{
            return dp[idx][buy][cap]=max(prices[idx]+solve(idx+1,1,cap-1,prices,dp),solve(idx+1,0,cap,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return solve(0,1,k,prices,dp);
        
        for(int i=n-1;i>=0;i--){
            
            for(int cap=1;cap<=k;cap++){
                
                dp[i][1][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                dp[i][0][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                
            }
            
        }
        return dp[0][1][k];
    }
};
class Solution {
public:
    int countOrders(int n) {
        unsigned long long int dp[501];
        dp[1]=1;
        dp[2]=6;
        if(n<=2)return dp[n];
         int mod=1e9+7;
        for(int i=3;i<=n;i++){
           unsigned long long int x=((i*2-1)%mod*dp[i-1]%mod)%mod;
            dp[i]=(x*i)%mod;
        }
       
        return dp[n]%mod;
    }
};
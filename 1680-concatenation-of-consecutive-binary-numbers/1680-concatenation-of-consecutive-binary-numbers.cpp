class Solution {
public:
    // 1 2 3
    int powMod(int x,int y,int mod){
        int ans=1;
        while(y){
            if(y&1){
                ans=((ans%mod)*1LL*(x%mod))%mod;
            }
            x=(x%mod*1LL*x%mod)%mod;
            y>>=1;
        }
        return ans;
    }
    int findLen(int n){
        int x=__builtin_clz(n);
        return 32-x;
    }
    int concatenatedBinary(int n) {
        int ans=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            int len=findLen(i);
            ans=((long long)ans<<len)%mod;
            ans+=i;
            ans%=mod;
        }
        return ans;
    }
};
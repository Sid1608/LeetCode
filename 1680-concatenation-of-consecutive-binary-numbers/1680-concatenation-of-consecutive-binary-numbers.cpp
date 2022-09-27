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
    int func(int n){
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long ans=0;
        long mod=1e9+7;
        int len=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                len++;
            }
            ans=((ans<<len)%mod+i)%mod;
        }
        
        return (int)ans;
    }
};
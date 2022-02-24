class Solution {
public:
    int maxSum(vector<int>& a, vector<int>&b ) {
        int n=a.size(),m=b.size();
		unsigned long long int c[n],d[m];
         int mod=1e9+7;
		unordered_map<int,int>p,q;
		for(int i=0;i<n;i++)p[a[i]]=i;
		for(int i=0;i<m;i++)q[b[i]]=i;
		c[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--)c[i]=(unsigned long long int)a[i]+c[i+1];
		d[m-1]=b[m-1];
		for(int i=m-2;i>=0;i--)d[i]=(unsigned long long int)b[i]+d[i+1];

        unsigned long long int ans=0,sum=0,bextra=0,aextra=0,dp1[n],dp2[m];
        for(int i=n-1;i>=0;i--){
            if(q.find(a[i])!=q.end()){
                if(d[q[a[i]]]+bextra>sum+a[i]){
                    dp1[i]=d[q[a[i]]]+bextra;
                    sum=d[q[a[i]]]+bextra;
                    cout<<bextra;
                }else{
                    dp1[i]=sum+a[i];
                    sum=(unsigned long long int)sum+a[i];
                    bextra+=(sum-d[q[a[i]]]-bextra);
                }
			}else{
                sum+=a[i];
                dp1[i]=sum;    
            }
            cout<<dp1[i]<<" ";
            ans=max(ans,dp1[i]);
            // ans%=mod;
        }
        sum=0;
        for(int i=m-1;i>=0;i--){
            if(p.find(b[i])!=p.end()){
                if(c[p[b[i]]]+aextra>sum+b[i]){
                    dp2[i]=c[p[b[i]]]+aextra;
                    sum=c[p[b[i]]]+aextra;
                }else{
                    dp2[i]=sum+b[i];
                    sum+=b[i];
                    aextra+=(sum-c[p[b[i]]]-aextra);
                }
			}else{
                sum+=b[i];
                dp2[i]=sum;    
            }
            ans=max(ans,dp2[i]);
        }
       
		return ans%mod;
    }
};
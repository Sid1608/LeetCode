class Solution {
public:
    int numberOfArithmeticSlices(vector<int>&a) {
       int n=a.size();
       if(n<3)
           return 0;
        int cnt=0;
        int dp[5001]={0};
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==a[i-1]-a[i-2]){
                dp[i]=dp[i-1]+1;
            }
            cnt+=dp[i];
        }
        return cnt;
    }
};
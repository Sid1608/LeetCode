class Solution {
public:
    double champagneTower(int g, int r, int c) {
        
        double dp[101][101]={0.0};
        dp[0][0]=g;
        for(int i=0;i<r;i++){
            for(int j=0;j<=c;j++){
                double x=max((dp[i][j]-1.0),0.0);
                if (x > 0) {
                    dp[i+1][j]+=(x/2.0);
                    dp[i+1][j+1]+=(x/2.0);
                }
                // cout<<dp[i+1][j]<<" "<<dp[i+1][j+1]<<endl;
            }
        }
        return min(dp[r][c],1.0);
    }
};
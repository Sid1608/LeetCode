class Solution {
public:
    int dp[101][51][51];
    int solve(int indx,int a,int b,vector<vector<int>>& costs,int n){
        
        if(indx==2*n){
            return 0;
        }
        if(dp[indx][a][b]!=-1)
            return dp[indx][a][b];
        int op1=INT_MAX,op2=INT_MAX;
        if(a<n){
            op1=costs[indx][0]+solve(indx+1,a+1,b,costs,n);
        }
        if(b<n)
            op2=costs[indx][1]+solve(indx+1,a,b+1,costs,n);
        return dp[indx][a][b]=min(op1,op2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        int n=costs.size();
        return solve(0,0,0,costs,n/2);
    }
};
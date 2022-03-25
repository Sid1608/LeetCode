class Solution {
public:
    
    //dp approach
    //for each person we have two options either send them to city a or city b. if a ==n then we will only take b and vice versa 
    //tc:o(n)
    //sc:o(101*51*51)+stack
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
        // memset(dp,-1,sizeof(dp));
        // int n=costs.size();
        // return solve(0,0,0,costs,n/2);
        //greedy
        //tc:o(nlogn) n:size of costs
        //sc:o(n)
        int n=costs.size();
        vector<pair<int,int>>diff(n);
        for(int i=0;i<n;i++){
            // cout<<costs[i][1]-costs[i][0]<<endl;
            diff[i]={costs[i][1]-costs[i][0],i};
        }
        sort(diff.begin(),diff.end());
        int b=0,res=0;
        for(int i=0;i<n;i++){
            if(b<n/2){
                res+=costs[diff[i].second][1];
                b++;
            }else{
                res+=costs[diff[i].second][0];
            }
        }
        return res;
    }
};
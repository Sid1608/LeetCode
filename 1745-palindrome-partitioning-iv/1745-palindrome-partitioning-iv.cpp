class Solution {
public:
    bool isPal(int i,int j, string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    bool solve(int idx,string& s,int count,vector<vector<int>>&dp){
        if(count==0){
            if(isPal(idx,s.size()-1,s)){
                return true;
            }
            return false;
        }
        if(idx>=s.size())return false;
        if(dp[idx][count]!=-1){
            return dp[idx][count]==1;
        }
        for(int i=idx;i<s.size()-1;i++){
            if(isPal(idx,i,s)){
                if(solve(i+1,s,count-1,dp))
                    return dp[idx][count]=true;
            }
        }
        return dp[idx][count]=false;
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return  solve(0,s,2,dp);
    }
};
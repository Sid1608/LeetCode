class Solution {
public:
    bool isPal(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int getPartioning(int idx,string s,vector<int>&dp){
        if(idx>=s.size())return 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=INT_MAX;
        for(int i=idx;i<s.size();i++){
            if(isPal(idx,i,s)){
                ans=min(ans,1+getPartioning(i+1,s,dp));
            }
        }
        return dp[idx]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return getPartioning(0,s,dp)-1;
    }
};
class Solution {
public:
    
    int solve(int idx,string s,unordered_map<string,int>&mp,vector<int>&dp){
        
        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx]!=-1)return dp[idx];
        string r="";
        for(int i=idx;i<s.size();i++){
            r+=s[i];
            if(mp.find(r)!=mp.end()){
                if(solve(i+1,s,mp,dp)){
                    return dp[idx]=1;
                }
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto w:wordDict ){
            mp[w]++;
        }
        vector<int>dp(s.size(),-1);
        return solve(0,s,mp,dp);
    }
};
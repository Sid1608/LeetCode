class Solution {
public:
    
    void solve(int idx,string& s,string r,vector<string>&ans,unordered_set<string>&mp){
        if(idx>=s.size()){
            r.pop_back();
            ans.push_back(r);
            return;
        }
        string word="";
        for(int i=idx;i<s.size();i++){
            word+=s[i];
           
            if(mp.find(word)!=mp.end()){
               
                
                solve(i+1,s,r+word+" ",ans,mp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp(wordDict.begin(),wordDict.end());
        vector<string>ans;
        string r="";
        solve(0,s,r,ans,mp);
        return ans;
    }
};
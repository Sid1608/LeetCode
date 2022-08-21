class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        
        stack<char>st;
        unordered_map<char,int>freq,vis;
        for(auto ch:s){
            freq[ch]++;
        }
        for(int i=0;i<n;i++){
            freq[s[i]]--;
            if(vis[s[i]]){
                continue;
            }
            
            while(!st.empty() and st.top()>s[i] and freq[st.top()]>0){
                vis[st.top()]=0;
                st.pop();
            }
            if(!vis[s[i]]){
                st.push(s[i]);
                vis[s[i]]=1;
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
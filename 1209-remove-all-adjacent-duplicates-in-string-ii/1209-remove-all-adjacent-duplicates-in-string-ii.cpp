class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        // st.push({s[0],1});
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            }
            if(st.top().first==s[i]){
                int sec=st.top().second+1;
                st.pop();
                if(sec==k){
                    
                    continue;
                }
                st.push({s[i],sec});
            }else{
                st.push({s[i],1});
            }
        }
        string res="";
        while(!st.empty()){
            int c=st.top().second;
            char r=st.top().first;
            st.pop();
            while(c--){
                res+=r;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        set<int>st;
        for(int i=0;i<n;i++){
            if(s[i]==c)
                st.insert(i);
        }
        vector<int>ans(n,INT_MAX);
        for(int i=0;i<n;i++){
            auto it=st.lower_bound(i);
            if(it==st.end())it--;
            ans[i]=min(ans[i],abs(i-(*it)));
            if(it!=st.begin()){
                it--;
                ans[i]=min(ans[i],abs(i-(*it)));
            }
        }
        return ans;
    }
};
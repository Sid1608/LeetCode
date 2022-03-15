class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        int rem[100000]={0};
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(st.size()){
                    st.pop();
                }else{
                    rem[i]=1;
                }
            }
        }
        while(st.size()){
            rem[st.top()]=1;
            st.pop();
        }
        string res="";
        for(int i=0;i<n;i++){
            if(!rem[i])res+=s[i];
        }
        return res;
    }
};